using System;
using System.Collections.Generic;

namespace Excercise_1
{
    public class ComposedMission : IMission
    {
        // static type member for the class.
        private static readonly string Type = "Composed";

        // data memeber for each ComposedMission object.
        private List<CalcDelegate> ActionList;

        private readonly string Name;

        //event handler.
        public event EventHandler<double> OnCalculate;

        //implementing imission methods.
        string IMission.Name => Name;

        string IMission.Type => Type;

        //constructor.
        public ComposedMission(string name)
        {
            ActionList = new List<CalcDelegate>();
            Name = name;
        }

        // add method to the composed mission.
        public ComposedMission Add(CalcDelegate calc)
        {
            ActionList.Add(calc);
            return this;
        }

        //calculate function, running all the functions sinquentially.
        public double Calculate(double value)
        {
            foreach (CalcDelegate action in ActionList)
            {
                value = action(value);
            }
            // invoking the event handler.
            OnCalculate?.Invoke(this, value);
            return value;
        }
    }
}