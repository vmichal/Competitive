using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season2/round1/krizova-situace.pdf*/
#endregion

namespace KrizovaSituace
{
    class Program
    {
        static void Main(string[] args)
        {
            string s;
            List<int> vystup = new List<int>();
            while ((s = Console.ReadLine()) != "0")
            {
                int mustek = Int32.Parse(s);
                List<int>[] mistnosti = new List<int>[mustek+1];
                bool[] navstiveno = new bool[mustek+1];
                int[] vzdalenost = new int[mustek+1];
                for (int i =1 ;i<=mustek ; i++)
                {
                    vzdalenost[i] = 0;
                    navstiveno[i] = false;
                    mistnosti[i] = new List<int>();
                    if (i > 1)
                    {
                        mistnosti[i].Add(i - 1);
                    }
                    if (i < mustek)
                    {
                        mistnosti[i].Add(i + 1);
                    }
                    if (i % 2 == 0)
                    {
                        mistnosti[i].Add(i / 2);
                    }
                    if (i % 3 == 0)
                    {
                        mistnosti[i].Add(i / 3);
                    }
                }
                Queue<int> fronta = new Queue<int>();
                fronta.Enqueue(mustek);
                navstiveno[mustek] = true;
                while (fronta.Count != 0 && vzdalenost[1] ==0)
                {
                    int pozice = fronta.Dequeue();
                    foreach(int i in mistnosti[pozice])
                    {
                        navstiveno[i] = true;
                        vzdalenost[i] = vzdalenost[pozice] + 1;
                        fronta.Enqueue(i);                        
                    }
                }
                vystup.Add(vzdalenost[1]);
            }
            foreach (int i in vystup)
            {
                Console.WriteLine(i);
            }

        }
    }
}
