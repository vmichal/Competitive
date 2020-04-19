using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season1/round2/uloziste.pdf*/
#endregion

namespace VesmirnaUloziste
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetInstanci = ToInt(Read());
            long[] vystup = new long[pocetInstanci];
            for (int i =0 ;i<pocetInstanci ; i++)
            {
                int pocetDruzic = ToInt(Read());
                string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                long[] obehy = new long[pocetDruzic];
                for (int a =0 ;a<pocetDruzic ;a++)
                {
                    obehy[a] = ToInt(s[a]);
                }                            
                long[] unikatni = obehy.Distinct().ToArray();
                vystup[i] = LCM(unikatni);            
            }  
            for (int i =0 ;i<pocetInstanci ; i++)
            {
                Console.WriteLine(vystup[i]);
            }                     
        }

        static long LCM(long[] numbers)
        {
            return numbers.Aggregate(Lcm);
        }
        static long Lcm(long a, long b)
        {
            return Math.Abs(a * b) / GCD(a, b);
        }
        static long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }
    }
}
