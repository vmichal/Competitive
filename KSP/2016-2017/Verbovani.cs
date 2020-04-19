using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Verbovani
{
    class Program
    {
        delegate string Read();
        delegate int ToInt(string s);
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetDomu = ToInt(Read());
            string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int[] chlapi = new int[pocetDomu];
            for (int i =0 ;i<pocetDomu ; i++)
            {
                chlapi[i] = ToInt(s[i]);
            }  
            s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int[] zbrane = new int[pocetDomu];
            for (int i=0 ;i<pocetDomu ; i++)
            {
                zbrane[i] = ToInt(s[i]);                
            }





        }
    }
}
