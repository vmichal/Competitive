using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MinovePole
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
            double[] vystup = new double[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                int pocetJezku = ToInt(Read());
                int pocetMin = ToInt(Read());
                int[] xJezku = new int[pocetJezku];
                int[] yJezku = new int[pocetJezku];
                int[] xMin = new int[pocetMin];
                int[] yMin = new int[pocetMin];
                string[] s;
                for (int i =0 ;i<pocetJezku ; i++)
                {
                    s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    xJezku[i] = ToInt(s[0]);
                    yJezku[i] = ToInt(s[1]);
                }
                for (int i =0 ;i<pocetMin ; i++)
                {
                    s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    xMin[i] = ToInt(s[0]);
                    yMin[i] = ToInt(s[1]);
                }

            }
            for (int a = 0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }
        }
    }
}
