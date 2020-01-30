using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KopaKopania
{
    class Program
    {
        static void Main(string[] args)
        {
            int pocetNerovnosti = Convert.ToInt32(Console.ReadLine());
            int jamy = 0;
            string nerovnosti = Console.ReadLine();
            for (int i =0 ;i<pocetNerovnosti ; i++)
            {
                if (nerovnosti[i] == '0')
                    jamy++;
            }
            Console.WriteLine(Math.Abs(pocetNerovnosti - jamy-jamy));
        }
    }
}
