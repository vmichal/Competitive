using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání  
/* Finále ročníku 2016/2017, příklad A.

Hurá! Do domova duchodců nainstalovali satelitní televizi! Krátce po instalaci se stala zajímavá věc! 
 * Každý stařeček má oblíbený a nenáviděný kanál.Když zří nenáviděný kanál, dojde k televizoru, 
 * přepne jej na svůj oblíbený kanál a v mžiku se vrátí na své místo.      

Na začátku dne dají sestry v domově televizi na počáteční kanál.Na jakém kanálu se televizor ustálí?

V případě, když se vydá přepnou televizi více důchodců najednou, tak ji přepne ten nejrychlejší.
Když se dva důchodci dostanou ve stejnou chvíli k televizoru, vyhraje ten, který je v seznamu výše.
Po přepnutí se všichni důchodci okamžitě vrátí.

Tvar vstupu
Na prvním řádku bude číslo T, počet testů. Na prvním řádku každého testu bude číslo N - počet důchodců. 
Na druhém bude číslo P - počáteční kanál. Pak bude následovat N trojic přirozených čísel značících postupně 
nenávidený a milovaný kanál a rychlost důchodce.


Tvar výstupu 
Na výstup vypište pro každý test jediné číslo, číslo kanálu na kterém se televize ustálí.Pokud se televize nikdy neustáli, vypište -1.


Lehká verze 
T ≤ 10
N ≤ 64
Každý kanál nenávidí nanejvýš jeden důchodce.
1 ≤ Rychlost důchodců ≤ 255
Pro každý kanál platí ≤ 128

Těžká verze   
T ≤ 10
N ≤ 50 000
1 ≤ Rychlost důchodců ≤ 65536
Pro každý kanál platí ≤ 50 000
*/
#endregion

namespace Duchodci
{
    class Duchodce
    {
        public int nenavidenyKanal;
        public int milovanyKanal;
        public int rychlost;
        public bool prepnul;
    }

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
            for (int a = 0 ; a < pocetTestu ; a++)
            {
                int pocetDuchodcu = ToInt(Read());
                Duchodce[] duchodci = new Duchodce[pocetDuchodcu];
                int kanal = ToInt(Read());
                for (int b = 0 ; b < pocetDuchodcu ; b++)
                {
                    string[] s = Console.ReadLine().Split(new List<char>() { ' ' }.ToArray(), StringSplitOptions.RemoveEmptyEntries);
                    duchodci[b] = new Duchodce()
                    {
                        nenavidenyKanal = Convert.ToInt32(s[0]),
                        milovanyKanal = Convert.ToInt32(s[1]),
                        rychlost = Convert.ToInt32(s[2]),
                        prepnul = false
                    };
                }
                while (true)
                {                                                                   
                    List<Duchodce> duchodciNenavidejiciKanal = new List<Duchodce>();
                    for (int c = 0 ; c < pocetDuchodcu ; c++)
                    {
                        if (duchodci[c].nenavidenyKanal == kanal)
                        {
                            duchodciNenavidejiciKanal.Add(duchodci[c]);
                        }
                    }
                    if (duchodciNenavidejiciKanal.Count == 0)
                    {
                        vystup[a] = kanal;
                        break;
                    }
                    Duchodce nejrychlejsiDuchodce = new Duchodce() { rychlost = 0 };
                    foreach (Duchodce d in duchodciNenavidejiciKanal)
                    {
                        if (d.rychlost > nejrychlejsiDuchodce.rychlost)
                        {
                            nejrychlejsiDuchodce = d;
                        }
                    }
                    kanal = nejrychlejsiDuchodce.milovanyKanal;
                    if (nejrychlejsiDuchodce.prepnul)
                    {
                        vystup[a] = -1;
                        break;
                    }
                    nejrychlejsiDuchodce.prepnul = true;
                }
            }
            for (int a = 0 ; a < pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }

        }
    }
}
