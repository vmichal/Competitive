using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CesilkovyHrnky
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetHrknu = ToInt(Read());
            int prvni = ToInt(Read());
            int minuly = prvni;
            bool roste = true;
            bool vystup = true;
            for (int i =1 ;i<pocetHrknu ; i++)
            {
                int dalsi = ToInt(Read());
                if (roste)
                {                              
                    if (dalsi > minuly)
                    {
                        minuly = dalsi; 
                        continue;
                    }
                    else
                    {
                        roste = false;
                        minuly = dalsi;
                        continue;
                    }
                }
                else
                {
                    if (dalsi > minuly && dalsi < prvni)
                    {
                        minuly = dalsi;
                    }
                    else
                    {
                        vystup = false;
                        break;
                        
                    }         
                }
            }
            if (vystup)
            {
                Console.WriteLine("Lze preskladat.");
            }
            else
            {
                Console.WriteLine("Nelze preskladat.");
            }
           


        }
    }
}
