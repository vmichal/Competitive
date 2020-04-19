using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PetrovoLusteniZpravy
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(" ".ToCharArray());
            int pocetZprav = int.Parse(s[0]);
            int delka = int.Parse(s[1]);
            string abeceda = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            int[][] vyskyty = new int[delka][];
            string nactene;                  
            for (int i = 0 ;i<delka ; i++)
            {                                        
                vyskyty[i] = new int[abeceda.Length];
                for (int j = 0 ;j<abeceda.Length ; j++)
                {
                    vyskyty[i][j] = 0;
                }
            }                               
            for (int i = 0 ;i<pocetZprav ; i++)
            {
                nactene = Console.ReadLine();
                for (int j = 0 ;j<delka ; j++)
                {
                    vyskyty[j][abeceda.IndexOf(nactene[j])]++;
                }                                                             
            }                                 
            nactene = "";
            for (int i = 0 ;i<delka ; i++)
            {
                int nejdelsiIndex = 0;
                for (int j = 0 ;j<abeceda.Length ; j++)
                {
                    if (vyskyty[i][j] > vyskyty[i][nejdelsiIndex])
                    {
                        nejdelsiIndex = j;
                    }
                }
                nactene += abeceda[nejdelsiIndex];
            }
            Console.WriteLine(nactene);

        }
    }
}
