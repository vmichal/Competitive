using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;   

#region Zadání 
/*
 Kasiopea ročník 2016/2017 - finále, úloha C
Zadání (Řešení)
Venku je spousta sněhu a pro pořádnou koulovanou jsme našli základnu. Pro jednoduchost budeme pracovat pouze s jejím průřezem. 
Základna je z ledu a známe její výšku na všech místech. Máme tedy N míst vedle sebe a známe výšku ledu na každém políčku.

Je velmi důležité mít působivou základnu. Na základnu můžeme ukládat sněhové koule a zajímá nás jak vysoko je můžeme vyskládat. 
Koule můžeme skládat jen na sebe. Pokud chceme tedy někam dát kouli musí být na všech třech místech pod ní (přímo, šikmo nalevo 
i šikmo napravo) buď led základny nebo jiná koule. Jinak by totiž koule spadla a rozbila se. Všimněte si, že to znamená, že v 
krajních sloupcích jistě žádnou kouli dát nemůžeme. Sněhu je dost a tedy můžeme vyrobit libovolně mnoho sněhových koulí.


Tvar vstupu   
Na prvním řádku bude číslo T, počet testů. Na prvním řádku každého testu bude číslo N, šířka základny. 
Pak bude následovat N čísel značících výšku základny v místě i.

Tvar výstupu   
Na výstup vypište pro každý test jediné číslo, maximální výšku základny po umístění koulí. Typicky tedy výšku nejvýše položené 
koule, v případech, kdy nemůžeme umístit kouli výš než je výška ledového základu, bude touto výškou právě výška nejvyššího 
ledového sloupce.

Lehká verze
T ≤ 15
N ≤ 1 000
0 ≤ výšky sloupců ≤ 1 000

Těžká verze 
T ≤ 15
N ≤ 1 000 000
H ≤ 1 000 000
Ukázkový vstup

2
7
0
10
3
3
3
10
0
9
10
3
3
3
10
1
3
2
1

Ukázkový výstup
12
12

Vysvětlení ukázkového vstupu a výstupu  
V krajních sloupcích nemůžeme mít ani jednu kouli, protože šikmo pod ní je už konec základny. 
Stejně tak neumístíme nic na dva vysoké sloupce ledu. Naopak díru uprostřed můžeme naplinit celou. 
Navíc na ní můžeme ještě postavit další čtyři koule. Pro lepší představu si prohlédni obrázek. 
Nejvýše položená koule se tedy může nacházet ve výšce 12.

Druhý vstup je velmi podobný. V tomto případe za druhým vysokým ledovým sloupcem sice koule ještě 
můžeme vyskládat (hned v nasledujícím sloupci až do výšky 4), nicméně si všimněte, že nám to nijak 
nepomůže. Nejvyššího bodu dosáhneme opět zasypáním díry za mezi vysokými ledovými sloupci.
 */

#endregion

namespace SnehovaZakladna
{  
    class Sloupec
    {
        public int vyska;
        public int maxVyskaZleva;
        public int maxVyskaZprava;
    }

    class Program
    {                          
        static void Main(string[] args)
        {
            int pocetTestu = Convert.ToInt32(Console.ReadLine());                   
            int[] vystup = new int[pocetTestu];                  
            for (int a = 0 ; a < pocetTestu ; a++)
            {
                int pocetSloupcu = Convert.ToInt32(Console.ReadLine());                     
                Sloupec[] Sloupce = new Sloupec[pocetSloupcu];  
                for (int i = 0 ; i < pocetSloupcu ; i++)            
                {
                    Sloupce[i] = new Sloupec();
                    int v = Convert.ToInt32(Console.ReadLine());
                    Sloupce[i].vyska = v;
                    Sloupce[i].maxVyskaZleva = v;
                    Sloupce[i].maxVyskaZprava = v;
                }
                int minulySloupecVyska = Sloupce[0].vyska;
                for (int i = 1 ;i<pocetSloupcu ; i++)
                {
                    if (Sloupce[i].vyska < minulySloupecVyska)
                    {
                        Sloupce[i].maxVyskaZleva = minulySloupecVyska + 1;                        
                    }
                    minulySloupecVyska = Sloupce[i].maxVyskaZleva;
                }
                minulySloupecVyska = Sloupce[pocetSloupcu - 1].vyska;
                for (int i = pocetSloupcu - 2 ; i > 0 ; i--) 
                { 
                    if (Sloupce[i].vyska < minulySloupecVyska)
                    {
                        Sloupce[i].maxVyskaZprava = minulySloupecVyska + 1;
                    }
                    minulySloupecVyska = Sloupce[i].maxVyskaZprava;
                }
                int nejvyssi = 0;
                int minimum;      
                for (int i =0 ;i<pocetSloupcu ; i++)
                {         
                    minimum = Math.Min(Sloupce[i].maxVyskaZleva, Sloupce[i].maxVyskaZprava);
                    if (minimum > nejvyssi)
                    {
                        nejvyssi = minimum;
                    }
                }
                vystup[a] = nejvyssi;   
            }
            for (int a = 0 ; a < pocetTestu ; a++)
            {                  
                Console.WriteLine(vystup[a].ToString());
            }
        }         
    }
}
