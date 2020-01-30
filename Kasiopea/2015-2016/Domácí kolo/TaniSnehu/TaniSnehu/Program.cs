using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání

/*Zadání (Řešení)
Z toho těžkého zápolení na finále Kasiopey se vám už točí hlava, a tak se radši jdete projít ven. A co nevidíte. Technické služby navezly sníh z chodníků na náměstí a tam vytvořily velikou hromadu sněhu. Povrch hromady je členitý z toho, jak si na ní děti dělaly skokánky, skluzavky, hradby a zákopy. Průřez hromadou si můžeme nakreslit na čtverečkovaný papír, pak vypadá nějak takto:


Přišla obleva a sníh odtává, každou hodinu odtají ty "čtverečky" sněhu, které jsou na okraji hromady. Z hromady na obrázku tedy po hodině zbyde toto:


Za jak dlouho roztaje celá hromada?

Tvar vstupu

Na prvním řádku vstupního souboru máte číslo T, počet testovacích vstupů v souboru.

Každý vstup vypadá tak, že na prvním řádku máte číslo N a na druhém řádku N čísel. Když budete průřez hromady číst po řádcích zleva, pak první číslo znamená výšku sněhu na prvním políčku. Druhé číslo je výška sněhu na druhém políčku a obecně i-té číslo znamená výšku sněhu v i-tém sloupečku.

Tvar výstupu

Do výstupního souboru vypište na j-tý řádek výstup j-tého vstupu. Výstupem nechť je jedno celé číslo, počet hodin, po kterých celá hromada odtaje.

Lehká verze

N ≤ 500
výšky sloupečků ≤ 1 000
Těžká verze

N ≤ 200 000
výšky sloupečků ≤ 1 000 000 000
Ukázkový vstup

1
6
1 3 3 3 3 2
Ukázkový výstup

3
Postupné tání v tomto případě je zobrazeno na následujícím obrázku. Na začátku je hromada v čase 0 (vlevo nahoře), dále v časech 1, 2 a 3. Celá hromada tedy roztaje v čase tři. */
#endregion


namespace TaniSnehu
{
    class Program
    {
        static void Main(string[] args)
        {
            int pocetTestu = Convert.ToInt32(Console.ReadLine());
            int[] vystup = new int[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                int[] sloupce = new int[Convert.ToInt32(Console.ReadLine())];
                string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                for (int i = 0 ;i<sloupce.Length ; i++)
                {
                    sloupce[i] = Convert.ToInt32(s[i]);                    
                }
                int[,] roztaje = new int[sloupce.Length, 2];
                for (int i =0 ;i<sloupce.Length ; i++)
                {
                    roztaje[i, 0] = i + 1;
                }
                roztaje[sloupce.Length - 1, 1] = 1;
                for (int i =sloupce.Length-2 ;i>=0 ; i--)
                {
                    roztaje[i, 1] = roztaje[i + 1, 1] + 1; 
                }
                for (int i =0 ;i<sloupce.Length ; i++)
                {
                    sloupce[i] = Math.Min(sloupce[i], roztaje[i, 0]);
                    sloupce[i] = Math.Min(sloupce[i], roztaje[i, 1]);
                }
                vystup[a] = sloupce[0];
                for (int i =1 ;i<sloupce.Length ; i++)
                {
                    if (sloupce[i] > vystup[a])
                    {
                        vystup[a] = sloupce[i];
                    } 
                }  
            }
            for (int a =0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }
        }
    }
}
                                              