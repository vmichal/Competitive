using System;                  

namespace ObavanaSkratka
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            int pocetZahradek = Convert.ToInt32(s[0]);
            int delkaTrvaniNapoje = Convert.ToInt32(s[1]);
            int[] vzdalenosti = new int[pocetZahradek];
            int[] casy = new int[pocetZahradek];
            s = Console.ReadLine().Split();
            for (int i = 0 ;i<pocetZahradek ; i++)
            {
                vzdalenosti[i] = Convert.ToInt32(s[i]);
            }
            s = Console.ReadLine().Split();
            for (int i = 0 ;i<pocetZahradek ; i++)
            {
                casy[i] = Convert.ToInt32(s[i]);
                if (casy[i] < vzdalenosti[i])
                {
                    Console.WriteLine(-1);
                    return;
                }
            }

            int zbylyCas = 0, vypitychLektvaru = 0;
            for (int i = 0 ;i<pocetZahradek ; i++)
            {
                if (vzdalenosti[i] <= zbylyCas)
                {
                    zbylyCas -= vzdalenosti[i];
                    continue;
                }
                vzdalenosti[i] -= zbylyCas;
                casy[i] -= zbylyCas;
                zbylyCas = 0;
                while (casy[i] < vzdalenosti[i] * 2 && vzdalenosti[i] > 0)
                {
                    vypitychLektvaru++;
                    vzdalenosti[i] -= delkaTrvaniNapoje;
                    casy[i] -= delkaTrvaniNapoje;
                }
                if (vzdalenosti[i] < 0)
                {
                    zbylyCas = -vzdalenosti[i];
                    continue;
                }  
            }
            Console.WriteLine(vypitychLektvaru);
        }
    }
}
