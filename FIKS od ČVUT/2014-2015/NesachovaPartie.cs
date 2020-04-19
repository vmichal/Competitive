using System;

#region Nefunkční řešení 
/*using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season1/round1/nesachova-partie.pdf*/
#endregion

namespace NesachovaPartie
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int strana = ToInt(Read());
            for (int y =0 ;y<strana ; y++)
            {
                for (int x=0 ;x<strana ; x++)
                {

                }
            }



        }
    }
}