using System.Collections.Generic;

namespace Excercise_1
{
    //declaring a type of delegate to use in this assignment, known by all in namespace.
    public delegate double CalcDelegate(double val);

    public class FunctionsContainer
    {
        //map for the delegates.
        private Dictionary<string, CalcDelegate> methodMap;

        // constructor.
        public FunctionsContainer()
        {
            methodMap = new Dictionary<string, CalcDelegate>();
        }

        // adding and getting functions from the map.
        public CalcDelegate this[string actionName]
        {
            get
            {
                if (methodMap.ContainsKey(actionName))
                {
                    return methodMap[actionName];
                }
                else
                {
                    //updating the function if needed.
                    methodMap[actionName] = val => val;
                    return methodMap[actionName];
                }
            }
            set => methodMap[actionName] = value;
        }

        public List<string> getAllMissions()
        {
            //returning function names.
            List<string> names = new List<string>();
            foreach (KeyValuePair<string, CalcDelegate> funcName in methodMap)
            {
                names.Add(funcName.Key);
            }
            return names;
        }
    }
}