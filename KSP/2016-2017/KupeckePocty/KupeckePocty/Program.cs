using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace KupeckePocty
{
    class Program
    {
        delegate string Read();
        delegate int ToInt(string s);
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetKupcu = ToInt(Read());
            Queue<decimal> kupci = new Queue<decimal>();
            int zaplacenaCastka;
            int suma = 0;
            for (int i =0 ;i<pocetKupcu ; i++)
            {
                zaplacenaCastka = ToInt(Read());
                kupci.Enqueue(zaplacenaCastka);
                suma += zaplacenaCastka;
            }
            decimal podil = suma / pocetKupcu;
            decimal d;
            Queue<decimal> dluznici = new Queue<decimal>();
            Queue<decimal> veritele = new Queue<decimal>();
            for (int i =0 ;i<pocetKupcu ; i++)
            {
                d = kupci.Dequeue();
                d -= podil;
                if (d > 0)
                {
                    veritele.Enqueue(d);
                }
                if (d < 0)
                {
                    dluznici.Enqueue(-d);
                }
            }

            decimal pohledavka;
            decimal dluh;
            while (veritele.Count != 0)
            {
                pohledavka = veritele.Dequeue();
                dluh = dluznici.Dequeue();
                if (pohledavka == dluh)
                {
                    continue;
                }
                if (pohledavka < dluh)
                {
                    dluznici.Enqueue(dluh - pohledavka);
                }
                else
                {
                    veritele.Enqueue(pohledavka - dluh);
                }
            }
            
        }   
    }
}
