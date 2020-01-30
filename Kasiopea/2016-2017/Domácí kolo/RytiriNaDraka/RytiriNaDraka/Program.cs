using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*
 Kasiopea 2016/2017, Domácí kolo, úloha C: Rytíři na draka 
 https://kasiopea.matfyz.cz/archiv/2016/doma/C/

 Zadání (Řešení)
Při řešení úloh Kasiopey jste vyčerpáním usnuli a zdá se vám o království, které sužuje zlý drak s mnoha hlavami. Král zavolal 
nejudatnější rytíře v celém království, aby z nich vybral ty, které pošle bojovat s drakem. Ten bude poražen, až mu odseknou 
všechny hlavy. Každý rytíř může odseknout jen jednu hlavu, a to nižší anebo stejně vysokou jako je on sám. Jako odměnu požadují 
všichni rytíři přesně tolik zlatých mincí, kolik je jejich výška v centrimetrech. Pomozte královi zjistit nejmenší možnou částku, 
kterou musí zaplatit, aby rytíři zabili draka.

Tvar vstupu    
Na prvním řádku vstupního souboru je číslo T, počet testů. Následuje T testů. V každém testu dostanete na prvním řádku čísla N a M, 
počet hlav a počet rytířů. Na druhém řádku dostanete N celých čísel reprezentující výšky hlav draka v centrimetrech. Na třetím řádku 
dostanete M čísel udávající výšky rytířů taky v centimetrech.   
Výšky hlav i rytířů jsou seřazené od nejmenší po největší. Můžete předpokládat, že se všechny výšky vejdou do běžné celočíselné proměnné.

Tvar výstupu  
Pro každý test vypište na samostatný řádek nejmenší počet mincí, za které daní rytíři draka zabijí. Pokud není možné draka zabít vypište -1.


Lehká verze        
T ≤ 10
N ≤ 200
M ≤ 200
Maximální výška rytířů i hlav je 500.

Těžká verze                 
T ≤ 10
N ≤ 1 000 000
M ≤ 1 000 000
Maximální výška rytířů i hlav je 10 000 000.

Ukázkový vstup      
3
3 7
130 140 150
125 131 135 142 146 153 160
5 10
163 175 179 181 194
150 165 170 175 180 182 190 193 195 200
3 4
160 160 170
140 150 160 170

Ukázkový výstup    
426
897
-1

Vysvětlení ukázkového vstupu a výstupu    
První drak má tři hlavy výšky 130, 140 a 150. Zvolíme pro ně rytíře s výškami 131, 142 a 153. Dohromady jim zaplatíme 426 mincí. 
Na druhém vstupu máme 5 hlav. Ideální rytíři mají výšky 165, 175, 180, 182 a 195. Výsledný počet mincí pro tento vstup je 897. 
Třetí vstup žádné řešení nemá, protože máme jen dva rytíře vysoké alespoň 160 centimetrů, zatímco musíme porazit tři hlavy.
*/

#endregion 

namespace RytiriNaDraka
{
    class Program
    {
        delegate int ToInt(string s);
        static void Main(string[] args)
        {
            ToInt ToInt = Convert.ToInt32;
            int pocetTestu = ToInt(Console.ReadLine());
            long[] vystup = new long[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int pocetHlav = ToInt(s[0]);
                int pocetRytiru = ToInt(s[1]);
                s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int[] hlavy = new int[pocetHlav];
                for (int i =0 ;i<pocetHlav ; i++)
                {
                    hlavy[i] = ToInt(s[i]);
                }           
                s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int[] rytiri = new int[pocetRytiru];
                for (int i = 0 ; i < pocetRytiru ; i++)
                {
                    rytiri[i] = ToInt(s[i]);
                }
                if (hlavy.Length > rytiri.Length)
                {
                    goto DosliRytiri;
                }
                long cena = 0;
                int indexRytire = -1;
                for (int i =0 ;i<pocetHlav ; i++)
                {
                    if (indexRytire < pocetRytiru - 1)
                    {
                        indexRytire++;
                    }
                    else
                    {
                        goto DosliRytiri;
                    }
                    while (hlavy[i] > rytiri[indexRytire])
                    {
                        if (indexRytire < pocetRytiru - 1)
                        {
                            indexRytire++;
                        }
                        else
                        {
                            goto DosliRytiri;
                        }
                    }
                    cena += rytiri[indexRytire]; 
                }
                vystup[a] = cena;
                continue;
                DosliRytiri:
                vystup[a] = -1;
            }
            for (int a = 0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);    
            }

        }
    }
}
