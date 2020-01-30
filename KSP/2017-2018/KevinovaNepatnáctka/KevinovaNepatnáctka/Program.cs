using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KevinovaNepatnáctka
{
    class Program
    {
        static void Main()
        {                           
            string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int maxY = Convert.ToInt32(s[0]);
            int maxX = Convert.ToInt32(s[1]);
            s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int y = Convert.ToInt32(s[0]);
            int x = Convert.ToInt32(s[1]);
            int pocetPohybu = Convert.ToInt32(Console.ReadLine());
            string pohyby = Console.ReadLine();
            for (int i = 0 ;i<pocetPohybu ; i++)
            {
                switch (pohyby[i])
                {
                    case '<':
                        {
                            if (x > 1)
                            {
                                x--;
                            }
                            break;
                        }
                    case '>':
                        {
                            if (x < maxX)
                            {
                                x++;
                            }
                            break;
                        }
                    case 'v':
                        {
                            if (y < maxY)
                            {
                                y++;
                            }
                            break;
                        }
                    case '^':
                        {
                            if (y > 1)
                            {
                                y--;
                            }
                            break;
                        }           
                }
            }
            Console.WriteLine(y + " " +x);

        }
    }
}
