using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season0/round2/sneci-zavody.pdf*/
#endregion

namespace SneciZavody
{
    class Program
    {
        static void Main(string[] args)
        {
            int indexSneka = Convert.ToInt32(Console.ReadLine());
            int pocetOtoceni = 0;
            for (int i =1 ;i<=indexSneka/2 ; i++)
            {
                if (indexSneka % i == 0)
                {
                    pocetOtoceni++;
                } 
            }
            if (pocetOtoceni % 2 == 0)
            {
                Console.WriteLine("Sneka se nevyplati otocit.");
            }
            else
            {
                Console.WriteLine("Sneka se vyplati otocit.");
            }
        }
    }
}
