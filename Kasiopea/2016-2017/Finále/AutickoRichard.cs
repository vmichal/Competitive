using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/* Kasiopea 2016/2017, finále, úloha D
 * https://kasiopea.matfyz.cz/soutez/D/
 * 
 * Zadání (Řešení)
Autíčko Richard cítí silnou bolest v převodovce. Má přece jenom obyčejnou a ta se brzy pokazí. Dokonce se po přejetí každé ulice Richardova rychlost snižuje. Proto si chce dojet pro novou převodovku. Pomozte Richardovi najít nejrychlejší cestu k nové převodovce od Ricarda.

Tvar vstupu

Na prvním řádku dostanete číslo T - počet testovacích vstupů. Na prvním řádku každého testu dostanete N - počet křižovatek, M - počet ulic spojujících křižovatky a Q - parametr udávající, kolikrát jede Richard pomaleji po projetí každé ulice. Následuje M řádek a na každé jsou tři čísla u, v a w znamenající, že mezi křižovatkou číslo u a křižovatkou číslo v vede cesta, kterou by Richard s funkční převodovkou ujel za w minut. Pokud však předtím projel k ulicemi, zabere mu cesta w·Qk minut.

Tvar výstupu

Pro každý testovací vstup vypište, za kolik nejméně minut se Richard může dostat z křižovatky číslo 1 ke křižovatce číslo N, kde se nachází nová převodovka.


Limity

Všechna čísla na vstupu kromě parametru Q jsou přirozená čísla. Q je zadáno ve formátu s desetinnou tečkou (viz vstup). Můžete předpokládat, že vždy existuje nějaká cesta z křižovatky číslo 1 do křižovatky číslo N a že výsledek bude vždy menší než 109. Výsledek vypište s přesností na alespoň tři platné cifry.
Lehká verze

T ≤ 10
2 ≤ N ≤ 1000
1 ≤ M ≤ 10 000
1 ≤ Q ≤ 2
Těžká verze

T ≤ 10
2 ≤ N ≤ 1 000 000
1 ≤ M ≤ 1 000 000
1 ≤ Q ≤ 2
Ukázkový vstup

1
5 6 2.0
1 2 1
2 3 1
1 3 5
3 4 1
4 5 1
3 5 5
Ukázkový výstup

11.0
Vysvětlení

Richard začíná na křižovatce 1 a chce se co nejrychleji dostat na křižovatku 5, nejrychlejší cesta vede přes křižovatky 3 a 4. Richard se nejprve z křižovatky 1 vydá na křižovatku 3 a cesta mu trvá pět minut. Za jízdy se mu převodovka trochu pokazí a cesta ke křižovatce 4 mu tak trvá dvě (1·2) minuty. Poslední úsek cesty mu trvá čtyři (1·22) minuty.
 */
#endregion

namespace AutickoRichard
{
    class Program
    {
        delegate int ToInt(string s);
        delegate string Read();
        static void Main(string[] args)
        {
            Read Read = Console.ReadLine;
            ToInt ToInt = Convert.ToInt32;
            int pocetTestu = ToInt(Read());
            double[] vystup = new double[pocetTestu];
            for (int a = 0 ;a<pocetTestu ; a++)
            {
                string[] s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int pocetKrizovatek = ToInt(s[0]);
                int pocetUlic = ToInt(s[1]);
                double zpomaleni = Convert.ToDouble(s[2]);
                List<int[]>[] graf = new List<int[]>[pocetKrizovatek];    
                double[] vzdalenost = new double[pocetKrizovatek];
                int[] projete = new int[pocetKrizovatek];
                for (int i =0 ;i<pocetKrizovatek ; i++)
                {
                    graf[i] = new List<int[]>();  
                    vzdalenost[i] = double.MaxValue;
                    projete[i] = int.MaxValue;
                }
                for (int i = 0 ;i<pocetUlic ; i++)
                {
                    s = Read().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    graf[ToInt(s[0])-1].Add(new int[2] { ToInt(s[1])-1, ToInt(s[2]) });
                    graf[ToInt(s[1])-1].Add(new int[2] { ToInt(s[0])-1, ToInt(s[2]) });
                }
                Queue<int> fronta = new Queue<int>();
                fronta.Enqueue(pocetKrizovatek - 1);
                vzdalenost[pocetKrizovatek - 1] = 0;
                projete[pocetKrizovatek - 1] = 0;
                while (fronta.Count != 0)
                {
                    
                }



                vystup[a] = vzdalenost[0];
            }


            for (int a =0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }            
        }
    }
}
