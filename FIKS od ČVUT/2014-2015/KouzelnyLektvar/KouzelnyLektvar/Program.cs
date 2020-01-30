using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KouzelnyLektvar
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetIngredienci = ToInt(Read());
            string[][] vstup = new string[pocetIngredienci][];
            for (int i=0 ;i<pocetIngredienci ; i++)
            {
                vstup[i] = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);                
            }
            Mlc();
            int nejvetsi = ToInt(vstup[0][0]);
            for (int i =1 ;i<pocetIngredienci ; i++)
            {
                if (ToInt(vstup[i][0]) < nejvetsi)
                {
                    CW(vstup[i - 1][0] + " " + vstup[i-1][1]);
                    continue;                      
                }
                else
                {
                    Mlc();
                    nejvetsi = ToInt(vstup[i][0]);
                    continue;   
                }                       
            }                           
        }
        static void Mlc()
        {
            Console.WriteLine("Fiksando, mlc!");
        }
        static void CW(string s)
        {
            Console.WriteLine(s);
        }
    }
}
