using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season4/round1/mesto.pdf*/
#endregion

#region
/*Read Read = Console.ReadLine;
        ToInt ToInt = Convert.ToInt32;

        int pocetTestu = ToInt(Read());
        for (int a = 0 ;a<pocetTestu ; a++)
        {
            int pocetBudov = ToInt(Read());
            int[] budovy = new int[1_000];
            int vyska, l, r;
            string[] s;
            for (int i = 0 ;i<1_000 ; i++)
            {
                budovy[i] = 0;
            }
            for (int i = 0 ;i<pocetBudov ; i++)
            {
                s = Read().Split(" ".ToCharArray());
                vyska = ToInt(s[0]);
                l = ToInt(s[1])+500;
                r = ToInt(s[2])+500;
                for (int j = l ;j<r ; j++)
                {
                    if (budovy[j] < vyska)
                    {
                        budovy[j] = vyska;
                    }
                }                                                            
            }
            int celkovyObsah = 0;
            for (int i = 0 ;i<1_000 ; i++)
            {
                celkovyObsah += budovy[i];
            }
            Console.WriteLine(celkovyObsah);
        }*/
#endregion

namespace SiluetaMesta
{
    class Program
    {
        delegate string Read();
        delegate int ToInt(string s);
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetTestu = ToInt(Read());
            for (int a = 0 ;a < pocetTestu ; a++)
            {
                int pocetBudov = ToInt(Read());
                Budova[] budovy = new Budova[pocetBudov];
                for (int i = 0 ;i<pocetBudov ; i++)
                {
                    budovy[i] = new Budova(Read());
                }
                int celkovaPlocha;

            }                         
        }

        class Budova
        {
            public int Vyska { get; set; }
            public int L { get; set; }
            public int R { get; set; }

            public Budova(string data)
            {
                string[] s = data.Split(" ".ToCharArray());
                Vyska = Convert.ToInt32(s[0]);
                L = Convert.ToInt32(s[1]);
                R = Convert.ToInt32(s[2]);
            }
        }
    }
              
}
                             