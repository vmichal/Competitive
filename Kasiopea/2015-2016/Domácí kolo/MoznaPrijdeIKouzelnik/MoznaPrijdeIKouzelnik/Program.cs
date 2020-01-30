using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání 
/*
 Kasiopea 2015/2016 Domácí kolo, úloha B
 Možná přijde i kouzelník
Na finále Kasiopey možná přijde i kouzelník a předvede kouzlo s létajícími králíky. Vypadá takto:

Na začátku stojí v řadě N králíků a každý z nich má na sobě tričko s číslem. Čísla jsou navzájem různá. 
Pak kouzelník dohromady K-krát mávne hůlkou vždy buď nahoru nebo dolů

Když mávne hůlkou prvním způsobem, tak všichni králíci vyletí do vzduchu a dopadnou na zem přesně v opačném pořadí, 
než stáli předtím. To jest ten, co byl první, je nyní poslední, druhý předposlední, atd. Z řady králíků 1 2 3 4 se tedy 
stane 4 3 2 1. Když mávne hůlkou druhým způsobem tak vyletí do vzduchu jen první a poslední králík a prohodí se. Z řady 4 3 2 1 se tak stane 1 3 2 4.

Máte zadané počáteční pořadí králíků, seznam, jak během kouzla kouzelník mával hůlkou. Zajímalo by vás, kteří králíci 
budou postupně stát na vašich oblíbených pozicích

Tvar vstupu                
Ve vstupním souboru máte na prvním řádku číslo T udávající počet zadání v souboru. Každé z nich vypadá následovně.   

Na prvním řádku jsou tři celá čísla N, K a P, kde N je počet králíků, K je počet mávnutí hůlkou a P 
je počet oblíbených pozic. Na druhém řádku máte N čísel králíků tak, jak stáli v řadě na začátku. Na třetím řádku 
je K čísel 1 nebo 2 udávajících, jak kouzelník postupně mával hůlkou, kde

1 znamená otočení všech králíků
2 prohození prvního a posledního králíka
Na čtvrtém řádku je P čísel. Přičemž i-té z nich označuje vaši i-tou oblíbenou pozici (pozice indexujeme od jedničky).

Tvar výstupu  
Do výstupního souboru vypište pro každý vstup na jeden řádek P čísel králíků, kteří na konci kouzla budou na místech, 
na která se ptáme. Vždy i-té číslo musí odpovídat králíkovi na vaší i-té oblíbené pozici.

Lehká verze 
1 ≤ T ≤ 20 – počet testovacích vstupů
1 ≤ N ≤ 500 – počet králíků
1 ≤ K ≤ 500 – počet mávnutí hůlkou
1 ≤ P ≤ 20 – počet pozic, které nás zajímají
0 ≤ čísla králíků ≤ 1 000 000
1 ≤ čísla pozic, na které se ptáme ≤ N

Těžká verze          
Stejné jako u lehké verze, pouze
1 ≤ N ≤ 200 000
1 ≤ K ≤ 300 000

Příklad vstupu 
1
5 3 3
1 2 3 4 5
1 2 1
1 3 5

Příklad výstupu  
5 3 1

 */

#endregion

namespace MoznaPrijdeIKouzelnik
{
    class Program
    {
        static void Main(string[] args)
        {
            int pocetTestu = Convert.ToInt32(Console.ReadLine());
            List<int>[] vystup = new List<int>[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                try
                {

                    string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    int pocetKraliku = Convert.ToInt32(s[0]);
                    int pocetMavnutiHulkou = Convert.ToInt32(s[1]);
                    int pocetOblibenychPozic = Convert.ToInt32(s[2]);
                    string[] s1 = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    int[] kralici = new int[pocetKraliku];
                    for (int i = 0 ; i < pocetKraliku ; i++)
                    {
                        kralici[i] = Convert.ToInt32(s1[i]);
                    }
                    string[] s2 = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    int pocetOtoceniKraliku = 0;
                    int pocetProhozeniPrvnihoAPosledniho = 0;
                    for (int i = 0 ; i < pocetMavnutiHulkou ; i++)
                    {
                        if (s2[i] == "1")
                        {
                            pocetOtoceniKraliku++;
                        }
                        else
                        {
                            pocetProhozeniPrvnihoAPosledniho++;
                        }
                    }
                    string[] s3 = Console.ReadLine().Split(new List<char>() { ' ' }.ToArray(), StringSplitOptions.RemoveEmptyEntries);
                    int[] oblibenePozice = new int[pocetOblibenychPozic];
                    for (int i = 0 ; i < pocetOblibenychPozic ; i++)
                    {
                        oblibenePozice[i] = Convert.ToInt32(s3[i])-1;
                    }
                    if (pocetProhozeniPrvnihoAPosledniho % 2 == 1)
                    {
                        int lastIndex = kralici.Length - 1;
                        int pomocna = kralici[0];
                        kralici[0] = kralici[lastIndex];
                        kralici[lastIndex] = pomocna;
                    }
                    if (pocetOtoceniKraliku % 2 == 1)
                    {
                        Array.Reverse(kralici);
                    }
                    vystup[a] = new List<int>();
                    for (int i = 0 ; i < pocetOblibenychPozic ; i++)
                    {
                        vystup[a].Add(kralici[oblibenePozice[i]]);
                    }
                }
                catch (Exception e)
                {
                    System.IO.StreamWriter w = new System.IO.StreamWriter("chyby.txt");
                    w.WriteLine(e + " cyklus " + a.ToString());
                    w.Close();
                }
            }                           
            for (int j = 0 ;j<pocetTestu ; j++)                        
            {
                foreach (int i in vystup[j])
                {
                    Console.Write(i + " ");
                }
                Console.Write("\n");
            }
        }
    }
}
