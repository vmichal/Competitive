using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

#region Zadání 
/*
Kasiopea 2015/2016, Domácí kolo, úloha F: Řezání klády

Zadání (Řešení)

Vracíte se zpátky do místnosti, kde probíhá finále Kasiopey, ale omylem jste vešli do jiných dveří. Tam schůzuje několik akademiků 
pracujících na grantu od dřevorubců. Pracují na programu, který naplánuje řezání dřeva tak, aby to pro pilu bylo co nejlevnější. 
Než si uvědomíte, že jste na špatném místě, tak si stihnete vyslechnout úlohu, kterou právě řeší:

Na pile mají kládu dlouhou L a tu potřebují rozřezat na konkrétních místech p1, ..., pN. Rozříznutí kusu o délce D ale stojí D peněz, 
kláda je totiž těžká, musí se zvedat speciálním jeřábem, jeho provoz vyžaduje množství energie přímo úměrné hmotnosti klády a energie 
stojí peníze. Za kolik nejméně peněz se dá kláda rozřezat?

Tvar vstupu   
Na prvním řádku vstupního souboru máte číslo T, počet testovacích vstupů v souboru.  
Každý testovací vstup se skládá ze dvou řádků. Na prvním z nich jsou dvě čísla L a N. L udává délku původní klády a N počet řezů, 
které je potřeba provést. Na druhém řádku jsou pak postupně čísla p1, ..., pN. Tato čísla jsou setříděna vzestupně.

Tvar výstupu
Pro každý testovací vstup vypište na samostatný řádek optimální cenu rozřezání původní klády podle zadání

Lehká verze 
T ≤ 10
N ≤ 8
L ≤ 100 000

Těžká verze   
T ≤ 10
N ≤ 500
L ≤ 1 000 000

Ukázkový vstup  
1
20 4
3 11 15 18

Ukázkový výstup 
45

Nejvýhodnější postup řezání bude nejprve rozříznout kládu na pozici 11. Řežeme celou kládu, tedy zaplatíme za celou její délku 20 peněz. 
Tím se nám rozpadne na dvě kratší klády. První z nich začíná na pozici 0 a končí na pozici 11, tu musíme ještě rozříznout na pozici 3, za 
což zaplatíme dalších 11 peněz. Druhá z kratších klád začíná na pozici 11 a končí na pozici 20, tu musíme rozříznout ještě dvakrát, 
a to na pozicích 15 a 18, nejlevněji vyjde nejprve řezat na pozici 15 (za to zaplatíme délku klády, tedy 9), a pak musíme ještě zbylý 
kus délky 5 rozřezat na pozici 18, za což zaplatíme 5 peněz. Dohromady tedy utratíme 20 + 11 + 9 + 5 = 45.
*/

#endregion

namespace RezaniKlady
{     
    class Klada
    {
        public int Pocatek { get; set; }
        public int Konec { get; set; }
        public double Polovina
        {
            get { return (Konec + Pocatek) / 2; }
        }
        public int Delka
        {
            get { return Konec - Pocatek; }
        }
    }

    class Program
    {
        private delegate int ToInt(string s);

        static StreamWriter writer = new StreamWriter("zapis.txt");
        static void Main(string[] args)
        {
            ToInt ToInt = Convert.ToInt32;
            int pocetTestu = Convert.ToInt32(Console.ReadLine());
            writer.WriteLine("Načtena proměnná počet testů o hodnotě " + pocetTestu.ToString());
            long[] vystup = new long[pocetTestu];
            writer.WriteLine("vytvořeno pole long[] vystup o délce " + vystup.Length.ToString());
            for (int a = 0 ;a<pocetTestu ; a++)
            {
                writer.WriteLine("\n\nPočíná cyklus číslo " + a.ToString());
                string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int delkaKlady = ToInt(s[0]);
                int pocetRezu = ToInt(s[1]);
                writer.WriteLine("Z konzole načten vstup, délka klády = " + delkaKlady.ToString() + ", počet řezů = " + pocetRezu.ToString());
                List<int> rezy = new List<int>();
                s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                writer.WriteLine("Inicializován list řezů a z Konzole načten string souřadnic řezů.");
                for (int i = 0 ; i < pocetRezu ; i++)
                {
                    rezy.Add(ToInt(s[i]));
                    writer.WriteLine("Do listu přidán řez č. " + i.ToString() + " v místě " + s[i]);
                }
                List<Klada> klady = new List<Klada>() { new Klada() { Pocatek = 0, Konec = delkaKlady } };
                writer.WriteLine("Inicializován list klád a do nj přidána jediná kláda o délce " + klady[0].Delka);
                long cena = 0;
                writer.WriteLine("Začíná while cyklus.");
                int cisloCyklu = 0;
                while (rezy.Count > 0)
                {
                    cisloCyklu++;
                    writer.WriteLine("\nCyklus číslo " + cisloCyklu.ToString() + " začíná, počet řezů v listu " + rezy.Count.ToString());
                    Klada k = klady[0];
                    int i = 0;
                    writer.WriteLine("Vytvořena reference na kládu (počátek " + k.Pocatek + ", konec " + k.Konec + ") a vynulována var i. Začíná menší cyklus.");
                    while (!(rezy[i] >= k.Polovina) && i < rezy.Count - 1)
                    {
                        i++;
                        writer.WriteLine("Cyklus na nalezení indexu řezu. Nová hodnota i je " + i.ToString() + "/" + (rezy.Count - 1).ToString());
                    }
                    writer.WriteLine("Menší cyklus končí.");
                    int vlevoRez;
                    int vpravoRez;
                    int rez;
                    writer.WriteLine("Inicializovány tři intové proměnné. Dóchází na logický check.");
                    if (i > 0)
                    {
                        writer.WriteLine("i(" + i.ToString() + ") je větší, než nula, běží první logická větev.");
                        vlevoRez = rezy[i - 1];
                        vpravoRez = rezy[i];
                        writer.WriteLine("Naplněny intové proměnné vlevoRez (index " + (i - 1).ToString() + ", souřadnice " + vlevoRez.ToString() + ") a vpravoRez (index " + i.ToString() + ", hodnota" + vpravoRez.ToString() + ").");
                        if (vpravoRez < k.Konec || vlevoRez > k.Pocatek)
                        {
                            writer.WriteLine("Logické if vyšlo true, alespoň jeden řez je v rozsahu klády.");
                            if (Math.Abs(vpravoRez - k.Polovina) > Math.Abs(vlevoRez - k.Polovina))
                            {
                                writer.WriteLine("Vlevorez je blíž k polovině.");
                                rez = vlevoRez;
                            }
                            else
                            {
                                writer.WriteLine("VpravoRez je blíž k polovině.");
                                rez = vpravoRez;
                            }
                        }
                        else
                        {
                            writer.WriteLine("Logické if vyšlo false, ani jeden řez není v rozsahu klády, ta je odebrána z listu.");
                            klady.Remove(k);
                            goto Dalsi;
                        }
                    }
                    else
                    {
                        writer.WriteLine("i (" + i.ToString() + ") není větší než nula a pokračuje druhá větev kódu");
                        if (rezy[0] < k.Konec)
                        {
                            writer.WriteLine("První řez je v rozsahu klády a proměnná řez získává hodnotu " + rezy[0]);
                            rez = rezy[0];
                        }
                        else
                        {
                            writer.WriteLine("První řez " + rezy[0] + " je v hajzlu (konec klády " + k.Konec + ") a kláda je smazána.");
                            klady.Remove(k);
                            goto Dalsi;
                        }
                    }
                    writer.WriteLine("Kláda o souřdnicích " + k.Pocatek + "-" + k.Konec + " je odstraněna ze seznamu.");
                    klady.Remove(k);
                    klady.Add(new Klada() { Pocatek = k.Pocatek, Konec = rez });
                    klady.Add(new Klada() { Pocatek = rez, Konec = k.Konec });
                    writer.WriteLine("Přidány dvě klády " + k.Pocatek + "-" + rez + " a " + rez + "-" + k.Konec);
                    rezy.Remove(rez);
                    writer.WriteLine("Odstranění řezu ze seznamu a k celkové sumě " + cena.ToString() + " za řezání se přičítá délka klády " + k.Delka);
                    cena += k.Delka;
                    writer.WriteLine("Cena po přičtení : " + cena.ToString());
                    Dalsi:
                    continue;
                }
                writer.WriteLine("Končí velký cyklus, hodnota ceny " + cena.ToString() + " se ukládá do proměnné vystup(" + a.ToString() + ")");
                vystup[a] = cena;
            }
            for (int a =0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
                writer.WriteLine("Do konzole vypsán výstup v hodnotě " + vystup[a].ToString());
            }
            writer.Close();
        }
    }
}
                             