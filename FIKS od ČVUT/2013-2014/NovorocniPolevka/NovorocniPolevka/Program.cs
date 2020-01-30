using System;
using System.Collections.Generic;
using System.Linq;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season0/round2/lesni-posta.pdf*/
#endregion

namespace NovorocniPolevka
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            ToInt ToInt = Convert.ToInt32;
            Read Read = Console.ReadLine;
            int[] pocetHub = new int[3];
            int[] houby1;
            int[] houby2;
            int[] houby3;
            pocetHub[0] = ToInt(Read());
            string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            houby1 = new int[s.Length];
            for (int i =0 ;i<s.Length ; i++)
            {
                houby1[i] = ToInt(s[i]);
            }

            pocetHub[1] = ToInt(Read());
            s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            houby2 = new int[s.Length];
            for (int i = 0 ; i < s.Length ; i++)
            {
                houby2[i] = ToInt(s[i]);
            }

            pocetHub[2] = ToInt(Read());
            s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            houby3 = new int[s.Length];
            for (int i = 0 ; i < s.Length ; i++)
            {
                houby3[i] = ToInt(s[i]);
            }
            int[] unikatni1 = houby1.Distinct().ToArray();
            int[] unikatni2 = houby2.Distinct().ToArray();
            int[] unikatni3 = houby3.Distinct().ToArray();
            int delka = unikatni1.Length;
            if (delka != unikatni2.Length || delka != unikatni3.Length || unikatni1.Union(unikatni2.Union(unikatni3)).ToArray().Length != delka )
            {
                Console.WriteLine("Polevku nelze varit.");                 
            }
            else
            {
                Console.WriteLine("Hromadky jsou v poradku.");
            }








        }
    }
}
