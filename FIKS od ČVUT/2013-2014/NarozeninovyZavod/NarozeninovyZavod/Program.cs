using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://fiks.fit.cvut.cz/files/tasks/season0/round1/narozeninovy-zavod.pdf*/
#endregion

namespace NarozeninovyZavod
{
    class Program
    {
        delegate string Read();
        delegate int ToInt(string s);
        static void Main(string[] args)
        {
            ToInt ToInt = Convert.ToInt32;
            Read Read = Console.ReadLine;
            string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int vyska = ToInt(s[0]);
            int sirka = ToInt(s[1]);
            int delkaPopisu = ToInt(s[2]);
            bool[,] stromy = new bool[sirka, vyska];
            int[,] tabulky = new int[sirka, vyska];
            int poziceX =0;
            int poziceY =0;
            int rychlostX =0;
            int rychlostY=0;
            for (int y=0 ;y<vyska ; y++)
            {
                s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                for (int x =0 ;x<sirka ; x++)
                {
                    switch (s[x])
                    {
                        case "S":
                            {
                                stromy[x, y] = true;
                                break;
                            }
                        case ".":
                            {
                                continue;
                            }
                        case "<":
                            {
                                poziceX = x;
                                poziceY = y;
                                rychlostX = -1;
                                rychlostY = 0;
                                break;
                            }
                        case ">":
                            {
                                poziceX = x;
                                poziceY = y;
                                rychlostX = 1;
                                rychlostY = 0;
                                break;
                            }
                        case "V":
                            {
                                poziceX = x;
                                poziceY = y;
                                rychlostX = 0;
                                rychlostY = 1;
                                break;
                            }
                        case "^":
                            {       
                                poziceX = x;
                                poziceY = y;
                                rychlostX = 0;
                                rychlostY = -1;
                                break;
                            }
                        default:
                            {
                                tabulky[x, y] = ToInt(s[x]);
                                break;
                            } 
                    }        
                }

            }
            string kroky = Read();
            int noveX = 0;
            int noveY = 0;            
            bool[] navstivena = new bool[9];
            for (int i =0 ;i<delkaPopisu ; i++)
            {
                if (kroky[i] == 'r')
                {
                    noveX = poziceX + rychlostX;
                    noveY = poziceY = rychlostY;
                    if (noveX > sirka || noveY > vyska || noveX < 0 || noveY < 0)
                    {     
                        Console.WriteLine("Zajic si vubec nepamatuje kudy bezel.");
                        goto Konec;
                    }
                    if (stromy[noveX, noveY])
                    {
                        continue;                        
                    }
                    if (tabulky[noveX,noveY] != 0)
                    {
                        navstivena[tabulky[noveX, noveY]] = true;
                    }
                    poziceX = noveX;
                    poziceY = noveY;
                }
            }
            int soucet = 0;
            for (int i =0 ;i<9 ; i++)
            {
                if (navstivena[i])
                {
                    soucet += i + 1;
                }  
            }







            Konec:



        }
    }
}
