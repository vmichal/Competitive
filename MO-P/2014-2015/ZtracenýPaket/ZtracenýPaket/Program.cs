using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ZtracenýPaket
{
    class Program
    {
        delegate string Read();
        delegate int ToInt(string s);
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetCisel = ToInt(Read());
            bool[] pakety = new bool[pocetCisel];
            for (int i =0 ;i<pocetCisel-1 ; i++)
            {
                pakety[ToInt(Read()) - 1] = true;                
            }
            for (int i = 0 ; i < pocetCisel ; i++)
            {
                if (!pakety[i])
                {
                    Console.WriteLine(i+1);
                    break;
                }
            }

        }
    }
}
