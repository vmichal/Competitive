using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season0/round1/bobrie-stavby.pdf*/
#endregion

namespace BobriStavby
{
    class Program
    {
        static void Main(string[] args)
        {
            string vstup = Console.ReadLine();
            Stack<int> svahy = new Stack<int>();
            int mnozstviVody = 0;
            for (int i = 0 ; i < vstup.Length ; i++)
            {
                if (vstup[i] == '\\')
                {
                    svahy.Push(i);
                }
                if (vstup[i] == '/' && svahy.Count > 0)
                {
                    int zacatek = svahy.Pop();
                    mnozstviVody += i - zacatek;                      
                }
            }
            Console.WriteLine(mnozstviVody);
        }
    }
}
