using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://kasiopea.matfyz.cz/archiv/2015/doma/H/*/
#endregion

namespace RozbitaKlavesnice
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetTestu = ToInt(Read());
            ulong[] vystup = new ulong[pocetTestu];
            for (int a=0 ;a<pocetTestu ; a++)
            {
                string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int delitel = ToInt(s[0]);
                int pocetCislic = ToInt(s[1]);
                int[] cislice = new int[pocetCislic];
                for (int i =0 ;i<pocetCislic ; i++)
                {
                    cislice[i] = ToInt(s[2 + i]);
                }

            }
            for (int a=0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }


        }
    }
}
