using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*https://kasiopea.matfyz.cz/archiv/2015/doma/A/

Představte si, že jedete na finále Kasiopey a rozhodli jste se jet vlakem.Naneštěstí probíhá velká železniční rekonstrukce a v provozu je 
pouze jediná trať.Dobrá zpráva je, že spojuje přímo vaše bydliště s Prahou, kde se koná Kasiopea.


Na této trati nyní jezdí několik linek, navíc z každé zastávky vyjíždí pouze jediná linka. Vaším cílem je dostat se z první zastávky 
do Prahy, což je N-tá zastávka. Protože všechny vlaky jedou směrem na Prahu, řekli jste si, že nejlepší bude vždy dojet až na konečnou 
daného vlaku, tam přestoupit na další vlak, zase dojet na konečnou a tak dále.

Pozor, trať pokračuje i za Prahu, může se stát, že vlak, do kterého nastoupíte, pojede až za ni, v takovém případě samozřejmě vystoupíte na té správné zastávce.

U každé zastávky víte, kolik zastávek směrem k Praze ujede vlak vyjíždějící z dané zastávky.Zajímalo by vás, kolika vlaky pojedete.

Tvar vstupu: 
Na vstupu máte na prvním řádku číslo T, počet testovacích vstupů v jednom souboru. Každý vstup vypadá tak, že na prvním řádku má číslo N 
a na druhém N čísel udávajících počty zastávek, které ujede vlak vyjíždějící z první, druhé, třetí až N-té zastávce.

Tvar výstupu:
Na výstup vypište pro každý testovací vstup na samostatný řádek jedno celé číslo udávající počet vlaků, jimiž pojedete

Lehká verze 
T ≤ 20
N ≤ 10

Těžká verze  
T ≤ 20
N ≤ 1 000

Ukázkový vstup  
4
2
1 2
4
1 8 3 4
5
1 1 1 1 1
8
1 4 2 2 1 1 3 3

Ukázkový výstup  
1
2
4
4

U druhého vstupu nasedneme na zastávce 1, ujedeme 1 zastávku a jsme na zastávce 2. Tam chytneme vlak, který nás veze 8 zastávek, 
takže je schopný nás vzít na 10. Zastávka 4 je ale naše cílová, takže tam vystoupíme.Jeli jsme dvěma vlaky.
*/

#endregion

namespace CestaVlakem
{
    class Program
    {
        static void Main(string[] args)
        {
            int pocetTestu = Convert.ToInt32(Console.ReadLine());
            int[] vystup = new int[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                int cilovaZastavka = Convert.ToInt32(Console.ReadLine());
                string[] s = Console.ReadLine().Split(new List<char>() { ' ' }.ToArray(), StringSplitOptions.RemoveEmptyEntries);
                int[] vlakyZeZastavek = new int[cilovaZastavka+1];
                for (int i=1 ;i<=cilovaZastavka ; i++)
                {
                    vlakyZeZastavek[i] = Convert.ToInt32(s[i-1]);
                }
                int pocetVlaku = 0;
                int aktualniZastavka = 1;
                while (aktualniZastavka < cilovaZastavka)
                {
                    aktualniZastavka += vlakyZeZastavek[aktualniZastavka];
                    pocetVlaku++;
                }                
                vystup[a] = pocetVlaku;
            }
            for (int a =0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a].ToString());
            }
        }
    }
}
