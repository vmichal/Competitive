using System;                      
using System.Linq;               

#region Zadání
/*https://www.ksp.sk/ulohy/zadania/1183/*/
#endregion

namespace ZrychlanieParkoviska
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int pocetMist = ToInt(s[0]);
            int pocetPohybu = ToInt(s[1]);
            bool[] plne = new bool[pocetMist];
            int[] spz = new int[pocetMist];  
            for (int i =0 ;i<pocetMist ; i++)
            {
                plne[i] = false;
                spz[i] = -1;
            }
            bool zaparkoval;
            for (int i =0 ;i<pocetPohybu ; i++)
            {
                zaparkoval = false;
                int auto = ToInt(Read());
                if (spz.Contains(auto))
                {
                    for (int j =0 ;j<pocetMist ; j++)
                    {
                        if (spz[j] == auto)
                        {
                            plne[j] = false;
                            spz[j] = -1;
                            Console.WriteLine(j);
                            break;
                        }
                    } 
                }
                else
                {
                    for (int j = 0 ;j<pocetMist ; j++)
                    {
                        if (!plne[j])
                        {
                            plne[j] = true;
                            spz[j] = auto;
                            Console.WriteLine(j);
                            zaparkoval = true;
                            break;
                        }
                    }   
                    if (!zaparkoval)
                    {
                        Console.WriteLine("plne");
                    }
                }       
            } 
        }
    }
}
