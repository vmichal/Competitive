using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RuseniStanic
{
    class Program
    {
        delegate string Read();
        delegate int ToInt(string s);
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int pocetStanic = ToInt(s[0]);
            int pocetLinek = ToInt(s[1]);
            int[] indexySousedu = new int[pocetStanic];
            int[] sousedi = new int[pocetLinek * 2];
            for (int i=0 ;i<pocetStanic ; i++)
            {
                indexySousedu[i] = i;
            }
            for (int i =0 ;i<pocetLinek ; i++)
            {
                s = Read().Split("".ToCharArray(),StringSplitOptions.RemoveEmptyEntries)¨;

            }

        }
    }
}
                        