using System;

namespace Excercise_1
{
    public class SingleMission : IMission
    {
        // static type member for the class.
        private static readonly string Type = "Single";

        // data memeber for each SingleMission object.
        private readonly CalcDelegate Action;

        private readonly string Name;

        //event handler.
        public event EventHandler<double> OnCalculate;

        //implementing imission methods.
        string IMission.Name => Name;

        string IMission.Type => Type;

        //constructor.
        public SingleMission(CalcDelegate action, string name)
        {
            Action = action;
            Name = name;
        }

        //calculate function.
        public double Calculate(double value)
        {
            value = Action(value);
            //invoking the event handler.
            OnCalculate?.Invoke(this, value);
            return value;
        }
    }
}