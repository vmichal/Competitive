using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season1/round1/oprava-letacku.pdf*/
#endregion

namespace OpravaLetacku
{
    class Program
    {
        static string vytisteno;
        static string pozadovano;
        static void Main(string[] args)
        {
            vytisteno = Console.ReadLine();
            pozadovano = Console.ReadLine();
            if (pozadovano.Length < vytisteno.Length)
            {
                goto Nejde;
            }
            bool zkusMazat = true;
            if (pozadovano.Length == vytisteno.Length)
            {
                zkusMazat = false;
            }
            if (zkusMazat)
            {
                int currentVytisteno = 0;
                for (int i =0 ;i<pozadovano.Length ; i++)
                {
                    if (currentVytisteno < vytisteno.Length)
                    {
                        if (pozadovano[i] == vytisteno[currentVytisteno])
                        {
                            currentVytisteno++;
                            continue;
                        }
                        while (vytisteno[currentVytisteno] != pozadovano[i])
                        {
                            if (currentVytisteno < vytisteno.Length)
                            {
                                currentVytisteno++;
                            }
                            else
                            {
                                zkusMazat = false;
                                goto Prohazovat;
                            }
                        }
                        currentVytisteno++;
                    }
                    else
                    {
                        zkusMazat = false;
                        goto Prohazovat;

                    }
                }
            }
            Console.WriteLine("M");
            return;
            Prohazovat:
            if (pozadovano.Length == vytisteno.Length)
            {
                while (!Poskladano())
                {
                    
                }



            }





            Nejde:
            Console.WriteLine("X");
            return;



        }

        static bool Poskladano()
        {
            bool srovnano = true;
            for (int i =0 ;i<pozadovano.Length ; i++)
            {
                if (pozadovano[i] != vytisteno[i])
                {
                    srovnano = false;
                }
            }
            return srovnano;
        }
    }
}
