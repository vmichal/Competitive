using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání 
/*
 FIKS 2013/2014, 1. kolo
 https://fiks.fit.cvut.cz/files/tasks/season0/round1/fiksikovy-maliny.pdf
     */
#endregion

namespace FiksikovyMaliny
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
            int[] nejmensiCisla = new int[3] { 1000, 1000, 1000 };
            int cislo;
            for (int i =0 ;i<pocetCisel ; i++)
            {
                cislo = ToInt(Read());
                if (cislo < nejmensiCisla[2])
                {
                    nejmensiCisla[2] = cislo;
                    if (cislo < nejmensiCisla[1])
                    {
                        nejmensiCisla[2] = nejmensiCisla[1];
                        nejmensiCisla[1] = cislo;
                        if (cislo < nejmensiCisla[0])
                        {
                            nejmensiCisla[1] = nejmensiCisla[0];
                            nejmensiCisla[0] = cislo;
                        }
                    }
                }
            }
            Console.WriteLine(nejmensiCisla[2]);


        }
    }
}
