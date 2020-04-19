using System;                    

namespace LiecivaAlpa
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(); 
            int pocetBojovniku = Convert.ToInt32(s[0]);
            int pocetKapek = Convert.ToInt32(s[1]);
            int[] bojovnici = new int[pocetBojovniku];
            for (int i = 0 ;i<pocetBojovniku ; i++)
            {
                bojovnici[i] = Convert.ToInt32(Console.ReadLine());
            }
            int maximum = 0;
            long celkem = 0;
            for (int i = pocetBojovniku-1 ;i>=0 ; i--)
            {
                celkem = bojovnici[i];
                long soucet = celkem;
                for (int j = pocetBojovniku-1 ;j>=i ; j--)
                {
                    if (soucet % pocetKapek == 0)
                    {
                        int mistni = j - i + 1;
                        if (maximum < mistni)
                        {
                            maximum = mistni;
                            break;
                        }
                    }
                    soucet -= bojovnici[j];
                }                                
            }
            Console.WriteLine(maximum);
        }
    }
}
                                             