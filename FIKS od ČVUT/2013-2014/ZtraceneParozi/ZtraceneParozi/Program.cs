using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season0/round1/ztracene-parozi.pdf*/
#endregion

namespace ZtraceneParozi
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            bool[] pole = new bool[s.Length+1];
            pole.Initialize();
            for (int i =0 ;i<s.Length ; i++)
            {
                pole[Convert.ToInt32(s[i])] = true;
            }
            for (int i = 0 ; i < s.Length + 1 ; i++)
            {
                if (!pole[i])
                {
                    Console.WriteLine(i);
                } 
            }
        }
    }
}
