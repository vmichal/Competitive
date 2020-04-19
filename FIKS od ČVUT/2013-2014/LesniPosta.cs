using System;
using System.Collections.Generic;
using System.IO;

#region Zadání 
/*https://fiks.fit.cvut.cz/files/tasks/season0/round2/lesni-posta.pdf*/
#endregion

namespace LesniPosta
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();

        static int pocetKrizovatek;
        static List<int[]>[] strom;
        
        static void Main(string[] args)
        {                  
            Read Read = Console.ReadLine;             
            ToInt ToInt = Convert.ToInt32;             
            pocetKrizovatek = ToInt(Read());                                
            int pocetZasilek = ToInt(Read());                               
            strom = new List<int[]>[pocetKrizovatek];                       
            string[] s;                                                                                                    
            for (int i = 0 ; i < pocetKrizovatek ; i++)
            {                                                                 
                strom[i] = new List<int[]>();
            }
            for (int i = 0 ; i < pocetKrizovatek * 2 - 2 ; i++)
            {     
                s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);                                 
                strom[ToInt(s[0]) - 1].Add(new int[2] { ToInt(s[1]) - 1, ToInt(s[2]) });
            }                                                                                                           
            Queue<int> zacatky = new Queue<int>();                                                                      
            Queue<int> destinace = new Queue<int>();
            for (int i = 0 ; i < pocetZasilek ; i++)
            {                                                                                                               
                s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);                                 
                zacatky.Enqueue(ToInt(s[0]) - 1);                                                                           
                destinace.Enqueue(ToInt(s[1]) - 1);
            }                                                                                                           
            long cas = 0;                                                                                               
            int poziceVeverky = 0;                                                                                      
            while (zacatky.Count != 0)
            {                                                                                                               
                int start = zacatky.Dequeue();                                                                              
                int konec = destinace.Dequeue();

                cas += HloubkoveProhledavani(poziceVeverky, start);                                          
                cas += HloubkoveProhledavani(start, konec);                                                  
                poziceVeverky = konec;
            }                                                                                            
            cas += HloubkoveProhledavani(poziceVeverky, 0);                                              
            Console.WriteLine(cas);
        }       
        
        static long HloubkoveProhledavani(int start, int konec)
        {
            bool[] navstivene = new bool[pocetKrizovatek];
            long[] vzdalenosti = new long[pocetKrizovatek];
            for (int i = 0 ; i < pocetKrizovatek ; i++)
            {
                navstivene[i] = false;
                vzdalenosti[i] = 0;
            }
            Queue<int> body = new Queue<int>();
            navstivene[start] = true;
            body.Enqueue(start);
            while (body.Count != 0 && vzdalenosti[konec] == 0)
            {
                int bod = body.Dequeue();
                foreach (int[] i in strom[bod])
                {
                    if (!navstivene[i[0]])
                    {
                        body.Enqueue(i[0]);
                        navstivene[i[0]] = true;
                        vzdalenosti[i[0]] = vzdalenosti[bod] + i[1];
                    }
                }
            }
            return vzdalenosti[konec];
        }                                
    }
}
