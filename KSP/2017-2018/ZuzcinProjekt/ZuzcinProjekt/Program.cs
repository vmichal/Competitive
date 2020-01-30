using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ZuzcinProjekt
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int pocetUcastniku = Convert.ToInt32(s[0]);
            int pocetDotazu = Convert.ToInt32(s[1]);
            List<int>[] vztahy = new List<int>[pocetUcastniku];  
            for (int i = 0 ; i < pocetUcastniku ; i++)
            {
                s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                vztahy[i] = new List<int>();
                for (int j = 0 ; j < s.Length ; j++)
                {
                    vztahy[i].Add(Convert.ToInt32(s[j]));
                }
            }                                 
            Queue<int> fronta = new Queue<int>();
            bool[] navstivene = new bool[pocetUcastniku];
            int[] pocetSousedu = new int[pocetUcastniku];
            for (int i = 0 ; i < pocetDotazu ; i++)
            {
                for (int j = 0 ; j < pocetUcastniku ; j++)
                {
                    navstivene[j] = false;
                    pocetSousedu[j] = 0;
                }
                s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                fronta.Enqueue(Convert.ToInt32(s[0]));
                navstivene[fronta.Peek()] = true;
                while (fronta.Count != 0)
                {
                    int ucastnik = fronta.Dequeue();
                    foreach (int u in vztahy[ucastnik])
                    {
                        if (!navstivene[u])
                        {
                            navstivene[u] = true;
                            fronta.Enqueue(u);
                            pocetSousedu[ucastnik]++;
                        }
                    }
                }
                Console.WriteLine(pocetSousedu[Convert.ToInt32(s[1])]);
            }
        }
    }
}
