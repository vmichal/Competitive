using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*
 * Kasiopea 2015/2016 Domácí kolo, úloha C
 * Zadání (Řešení)
Dorazili jste na místo konání soutěže a k obědu jste dostali bagetu. Ta je hodně dlouhá a také pořádně naplněná. 
Když si vezmete metr a položíte ho vedle bagety, můžete si změřit, na kterém centimetru od začátku začíná a 
na kterém končí kolečko salámu, plátek sýra, salát, okurka, vajíčko nebo některá z dalších výborných náplní.

Jste už pořádně hladoví, ale také nedočkaví. Kdy se už konečně dostanete na to nejlepší místo v bagetě? Tím 
myslíme takové místo, ve kterém se nachází nejvíce vrstev náplně. A kolik jich bude?

Tvar vstupu   
Na prvním řádku vstupu je číslo T, počet baget, které máme v testovacím souboru.    
Každá bageta je zadaná takto: Na prvním řádku je číslo N, to je počet přísad v bagetě. Na dalších N řádcích 
jsou vždy dvě čísla A a B, která znamenají, že nějaký kousek náplně začíná na centimetru s číslem A 
(měřeno od začátku bagety) a končí na centimetru B.

Tvar výstupu  
Na výstupu očekáváme pro každou bagetu jedno číslo na samostatném řádku, a to největší počet náplní, 
které se nachází na jednom místě. Pokud jedna surovina na určitém místě bagety končí a jiná ve stejném 
začíná, tak počítáme, že na takovém místě se nachází obě náplně.


Lehká verze
0 ≤ N ≤ 1 000
0 ≤ A ≤ B ≤ 1 000

Těžká verze
0 ≤ N ≤ 10 000
0 ≤ A ≤ B ≤ 1 000 000 000

Ukázkový vstup
3
3
0 4
2 6
4 6
0
2
1 3
4 5

    Ukázkový výstup:       
3
0
1

 */

#endregion

namespace PestraBageta
{
    class Prisada
    {
        public int pocatek;
        public int konec;

        public bool JeVRozsahu(int centimetr)
        {
            if (centimetr <= konec && centimetr >= pocatek) 
            {
                return true;
            }
            return false;             
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int pocetTestu = Convert.ToInt32(Console.ReadLine());
            int[] vystup = new int[pocetTestu];
            for (int a = 0 ;a<pocetTestu ; a++)
            {
                int pocetPrisad = Convert.ToInt32(Console.ReadLine());
                Prisada[] prisady = new Prisada[pocetPrisad];     
                for (int i =0 ;i<pocetPrisad ; i++)
                {
                    string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    int z = Convert.ToInt32(s[0]);
                    int k = Convert.ToInt32(s[1]);      
                    prisady[i] = new Prisada() { pocatek = z, konec = k };
                }
                int maxPocetPrisad = 0;   
                for (int i=0 ;i<pocetPrisad ; i++)
                {
                    int pocetPrisadZde = 0;
                    int centimetr = prisady[i].konec;
                    for (int j = 0 ;j<pocetPrisad ; j++)
                    {
                        if (prisady[j].pocatek <= centimetr && prisady[j].konec >= centimetr)
                        {
                            pocetPrisadZde++;
                        }
                    }
                    if (pocetPrisadZde > maxPocetPrisad)
                    {
                        maxPocetPrisad = pocetPrisadZde;
                    }
                }
                vystup[a] = maxPocetPrisad;       
            }
            for (int a =0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }
        }
    }
}
