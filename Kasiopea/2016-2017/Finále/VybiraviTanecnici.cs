using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*
 * Kasiopea ročník 2016/2017 - finále, úloha B
 Zadání (Řešení)
V tanečních chceme vytvořit páry. U každého tanečníka víme výšku, pohlaví a to, zda chce tancovat s nižším nebo vyšším partnerem 
(musí být ostře vyšší nebo nižší, rovnosti se nepřipouštějí). Každý tanečník chce tancovat s opačným pohlavím. Tanečník, 
který zůstane sám, není spokojný. Zajímalo by nás, zda dokážeme vytvořit páry tak, aby byli všichni tanečníci spokojení.


Tvar vstupu 
Na prvním řádku bude číslo T, počet testů. Na prvním řádku každého testu bude číslo N, počet tanečníků, a za ním N řádků s tanečníky. 
Na každém z těch řádků budou v tomto pořadí oddělené mezerami tři údaje: číslo vyjadrující výšku tanečníka, písmeno 'M' označující 
muže nebo písmeno 'F' označující ženu a písmeno 'V' nebo 'N' - to, zda chce daný tanečník vyššího nebo nižšího partnera.

Tvar výstupu 
Na výstup vypíšte na jeden řádek 'ano' v případě, že páry dokážeme vytvořit, a 'ne' v případě, že se to nedá.

Lehká verze
T ≤ 10
N ≤ 200
Tanečníci nebudou vyšší než 500.

Těžká verze  
T ≤ 10
N ≤ 250 000 
Tanečníci nebudou vyšší než 500 000.

Ukázkový vstup  
2
6
170 M N
168 F V
165 M V
172 F N
175 F V
180 M N
3
170 M N
159 F V
176 M N

Ukázkový výstup 
ano
ne
  */
#endregion

namespace VybiraviTanecnici
{
    class Tanecnik
    {
        public int vyska;
        public bool muz;
        public bool preferujeVyssi;
    }

    class Program
    {
        static void Main(string[] args)
        {
            int pocetTestu = Convert.ToInt32(Console.ReadLine());
            bool[] vystup = new bool[pocetTestu];   
            for (int a = 0 ;a<pocetTestu ; a++)
            {
                vystup[a] = true;
                int pocetTanecniku = Convert.ToInt32(Console.ReadLine());
                if (pocetTanecniku % 2 != 0)
                {
                    vystup[a] = false;
                    break;
                }
                List<Tanecnik> muziPrefV = new List<Tanecnik>();
                List<Tanecnik> muziPrefN = new List<Tanecnik>();
                List<Tanecnik> zenyPrefV = new List<Tanecnik>();
                List<Tanecnik> zenyPrefN = new List<Tanecnik>();  
                for (int b=0 ;b<pocetTanecniku ; b++)
                {
                    string[] s = Console.ReadLine().Split(new List<char>() { ' ' }.ToArray(),StringSplitOptions.RemoveEmptyEntries);
                    Tanecnik t = new Tanecnik()
                    {
                        vyska = Convert.ToInt32(s[0]),
                        muz = (s[1] == "M"),
                        preferujeVyssi = (s[2] == "V")

                    };        
                    if (t.muz)
                    {
                        if (t.preferujeVyssi)
                        {
                            muziPrefV.Add(t);
                            continue;
                        }
                        muziPrefN.Add(t);
                        continue;
                    }
                    if (t.preferujeVyssi)
                    {
                        zenyPrefV.Add(t);
                        continue;
                    }
                    zenyPrefN.Add(t);
                    continue;
                }
                if ( (zenyPrefV.Count + zenyPrefN.Count) != (muziPrefV.Count+ muziPrefN.Count) )
                {
                    vystup[a] = false;
                    break;
                }         
                muziPrefV.Sort((x, y) => x.vyska.CompareTo(y.vyska));  
                muziPrefN.Sort((x, y) => x.vyska.CompareTo(y.vyska));
                zenyPrefV.Sort((x, y) => x.vyska.CompareTo(y.vyska));
                zenyPrefN.Sort((x, y) => x.vyska.CompareTo(y.vyska));   
                for (int i = 0 ;i<muziPrefN.Count ; i++)
                {
                    if (muziPrefN[i].vyska < zenyPrefV[i].vyska)
                    {
                        vystup[a] = false;
                        goto Konec;                     
                    }
                }
                for (int i = 0 ;i<muziPrefV.Count ; i++)
                {
                    if (muziPrefV[i].vyska > zenyPrefN[i].vyska)
                    {
                        vystup[a] = true;
                        goto Konec;
                    }
                }
                Konec:
                continue;
            }
            for (int i = 0 ; i<pocetTestu ; i++)
            {
                if (vystup[i])
                {
                    Console.WriteLine("ano");
                }
                else
                {
                    Console.WriteLine("ne");
                }
            }

        }
    }
}
