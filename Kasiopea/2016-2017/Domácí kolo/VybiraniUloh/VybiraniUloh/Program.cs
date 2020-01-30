using System;               
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*
 Kasiopea 2016/2017, domácí kolo, úloha A: Vybírání úloh
 Zadání (Řešení)

Organizátoři programátorské soutěže Kasiopea vybírají úlohy do finálového kola. Úlohy jsou očíslovány od 1 do N. 
U každé úlohy známe počet hlasů, které od organizátorů dostala. Zajímá nás, jaká úloha dostala nejvyšší počet hlasů, 
a byla tak vybrána do finále. Máte zaručeno, že neexistují dvě úlohy se stejným počtem hlasů.

Tvar vstupu                                                         
Na prvním řádku vstupního souboru je číslo T, počet problémů, které musíte vyřešit. Pro každý problém dostanete na 
prvním řádku jedno číslo N udávající počet úloh. Na dalším řádku následuje N nezáporných čísel oddělených mezerou. 
Číslo na i-té pozici nám říká, kolik hlasů dostala i-tá úloha. Všechny čísla se vejdou do běžného integeru.


Tvar výstupu                                   
Pro každý problém vypište na samostatný řádek číslo úlohy s nejvyšším počtem hlasů.

Lehká verze                      
T ≤ 10
N ≤ 100

Těžká verze            
T ≤ 10
N ≤ 1 000 000

Ukázkový vstup      
2
5
0 8 4 3 1
10
1 5 9 7 8 6 2 3 20 0

Ukázkový výstup      
2
9

Vysvětlení ukázkového vstupu a výstupu    
V prvním případě získala nejvíce hlasů, tedy osm, druhá úloha. Odpověď je tedy 2. V případě druhém nejvíce hlasů získala úloha 9.
*/

#endregion 

namespace VybiraniUloh
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();

        static void Main(string[] args)
        {
            ToInt ToInt = Convert.ToInt32;
            Read Read = Console.ReadLine;
            int pocetTestu = ToInt(Read());
            int[] vystup = new int[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                int pocetUloh = ToInt(Read());
                string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);   
                int cisloVybraneUlohy = 0;
                int maxPocetHlasu = 0;
                int tatoUloha;
                for (int i =0 ;i<pocetUloh ; i++)
                {
                    tatoUloha = ToInt(s[i]);        
                    if (tatoUloha > maxPocetHlasu)
                    {
                        maxPocetHlasu = tatoUloha;
                        cisloVybraneUlohy = i+1;
                    }                    
                }
                vystup[a] = cisloVybraneUlohy;    
            }
            for (int a = 0 ; a < pocetTestu ;a++)
            {
                Console.WriteLine(vystup[a]);
            }


        }
    }
}
