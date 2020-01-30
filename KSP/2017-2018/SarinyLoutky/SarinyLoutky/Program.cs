using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SarinyLoutky
{
    class Program
    {
        static void Main()
        {
            string[] s = Console.ReadLine().Split(" ".ToCharArray(),StringSplitOptions.RemoveEmptyEntries);
            int pocetLoutek = int.Parse(s[0]);
            int maxHmotnost = int.Parse(s[1]);
            List<int> loutkyList = new List<int>();
            for (int i = 0 ;i<pocetLoutek ; i++)
            {
                loutkyList.Add(int.Parse(Console.ReadLine()));  
            }
            loutkyList.Sort();
            int[] loutky = loutkyList.ToArray();     
            int zacatek = 0, konec = pocetLoutek - 1, pocetVesaku = 0;   
            while (zacatek <= konec)
            {                
                if (loutky[konec]+loutky[zacatek] <= maxHmotnost)
                {                                          
                    zacatek++;
                }   
                konec--;
                pocetVesaku++;  
                                
            }    
            Console.WriteLine(pocetVesaku);  
        }
    }
}
