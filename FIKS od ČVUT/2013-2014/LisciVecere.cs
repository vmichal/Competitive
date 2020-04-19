using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season0/round2/liscia-vecera.pdf*/
#endregion

namespace LisciVecere
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int vyska = ToInt(s[0]);
            int sirka = ToInt(s[1]);
            int[,] pole = new int[sirka, vyska];
            int noraX = 0;
            int noraY = 0;
            bool[,] navstiveno = new bool[sirka, vyska];
            int[,] pocetSkokuSem = new int[sirka, vyska];
            for (int y =0 ;y<vyska ; y++)
            {
                s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                for (int x =0 ;x<sirka ; x++)
                {
                    pole[x, y] = ToInt(s[x]);
                    if (pole[x,y] == 0)
                    {
                        noraX = x;
                        noraY = y;
                    }
                    navstiveno[x, y] = false;
                    pocetSkokuSem[x, y] = 0;
                }
            }
            Queue<int> xs = new Queue<int>();
            Queue<int> ys = new Queue<int>();

            xs.Enqueue(0);
            ys.Enqueue(0);
            navstiveno[0, 0] = true;

            while (xs.Count != 0 && pocetSkokuSem[noraX,noraY] ==0)
            {
                int x = xs.Dequeue();
                int y = ys.Dequeue();
                int skok = pole[x, y];
                if (x + skok < sirka && !navstiveno[x+skok,y]) 
                {
                    xs.Enqueue(x + skok);
                    ys.Enqueue(y);
                    navstiveno[x + skok, y] = true;
                    pocetSkokuSem[x + skok, y] = pocetSkokuSem[x, y] + 1;
                }
                if (x - skok >= 0 && !navstiveno[x - skok, y])
                {
                    xs.Enqueue(x - skok);
                    ys.Enqueue(y);
                    navstiveno[x - skok, y] = true;
                    pocetSkokuSem[x - skok, y] = pocetSkokuSem[x, y] + 1;
                }
                if (y + skok < vyska && !navstiveno[x, y+skok])
                {
                    xs.Enqueue(x);
                    ys.Enqueue(y+skok);
                    navstiveno[x, y+skok] = true;
                    pocetSkokuSem[x, y+skok] = pocetSkokuSem[x, y] + 1;
                }
                if (y - skok >= 0 && !navstiveno[x, y-skok])
                {
                    xs.Enqueue(x);
                    ys.Enqueue(y-skok);
                    navstiveno[x, y-skok] = true;
                    pocetSkokuSem[x, y-skok] = pocetSkokuSem[x, y] + 1;
                }                                 
            }
            int krokyLisky = ToInt(Read());
            string st;
            if (!navstiveno[noraX,noraY])
            {
                st = "Zajac ti sam vbehne do papule!";
                goto Konec;
            }
            if (krokyLisky <= pocetSkokuSem[noraX, noraY])
            {
                st = "Liska bez!";
                goto Konec;
            }
            else
            {
                st = "Dnes se nenajes.";
                goto Konec;
            }


            Konec:
            Console.WriteLine(st);
        }
    }
}
