using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání 
/*https://fiks.fit.cvut.cz/files/tasks/season0/round1/oriskove-trable.pdf*/
#endregion

namespace OriskoveTrable
{
    class Program
    {
        static void Main(string[] args)
        {
            int strana = Convert.ToInt32(Console.ReadLine());
            bool[,] pole = new bool[strana, strana];
            pole.Initialize();
            string s;
            for (int i =0 ;i<strana ; i++)
            {
                s = Console.ReadLine();
                for (int j=0 ;j<strana ; j++)
                {
                    if (s[j] == 'V')
                    {
                        pole[i, j] = true;
                    }
                }    
            }    
            
        }
    }
}
