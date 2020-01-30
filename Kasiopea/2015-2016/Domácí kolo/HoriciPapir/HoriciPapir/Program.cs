using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání
/*
Finále Kasiopey začíná. Dostali jste papíry na poznámky, ale nejen to. Máte list čtverečkovaného papíru a 
zapalovač. A co vás nenapadne, některé čtverečky zespodu zapálíte a pak budete sledovat, jak papír krásně 
hoří. Oheň se šíří tak, že každou vteřinu začnou hořet všechna sousední políčka ohnivých políček. Za sousední 
považujeme ta, která se navzájem dotýkají stranami nebo rohy.  
Za kolik vteřin celý papír shoří?

Tvar vstupu   
Na prvním řádku každého testovacího souboru bude číslo T, počet vstupů v souboru.   
Každý vstup vypadá tak, že na jeho prvním řádku máte čísla S, V a N. S udává šířku papíru, V výšku a N počet ohýnků.

Na dalších N řádcích máte vždy dvě čísla s a v, to znamená, že jste zapálili čtvereček v s-tém sloupečku 
a v-tém řádku, tyto čtverečky začnou hořet v čase 0. Sloupečky i řádky počítáme od nuly.

Tvar výstupu       
Odpovědi na vstupy vypište na samostatné řádky v tom pořadí, v jakém se vyskytovaly ve vstupním souboru.

Lehká verze     
S, V ≤ 50
N ≤ S · V
0 ≤ s < S
0 ≤ v < V

Těžká verze  
S, V ≤ 1 000
N ≤ S · V
N ≤ 100 000
0 ≤ s < S
0 ≤ v < V

Ukázkový vstup  
1
5 4 2
0 0
2 2

Ukázkový výstup 
2
*/
#endregion

#region Pomalejší řešení
/*
  static void Main(string[] args)
    {
        int pocetTestu = Convert.ToInt32(Console.ReadLine());
        int[] vystup = new int[pocetTestu];
        for (int a = 0 ; a < pocetTestu ; a++)
        {
            string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            int sirka = Convert.ToInt32(s[0]);
            int vyska = Convert.ToInt32(s[1]);
            int pocetOhnu = Convert.ToInt32(s[2]);
            Pole[,] pole = new Pole[sirka, vyska];
            for (int x = 0 ; x < sirka ; x++)
            {
                for (int y = 0 ; y < vyska ; y++)
                {
                    pole[x, y] = new Pole() { x = x, y = y, hori = false, vzdalenost = 1000 };
                }
            }
            List<Pole> ohne = new List<Pole>();
            for (int i = 0 ; i < pocetOhnu ; i++)
            {
                string[] souradnice = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int x = Convert.ToInt32(souradnice[0]);
                int y = Convert.ToInt32(souradnice[1]);
                pole[x, y].hori = true;
                ohne.Add(pole[x, y]);
            }
            int c_Vzdalenost;
            int maxVzdalenost = 0;
            for (int x = 0 ; x < sirka ; x++)
            {
                for (int y = 0 ; y < vyska ; y++)
                {
                    Pole p = pole[x, y];
                    if (p.hori)
                    {
                        continue;
                    }
                    foreach (Pole o in ohne)
                    {
                        c_Vzdalenost = Math.Max(Math.Abs(o.x - p.x), Math.Abs(o.y - p.y));
                        if (c_Vzdalenost < p.vzdalenost)
                        {
                            p.vzdalenost = c_Vzdalenost;
                        }
                        if (c_Vzdalenost < maxVzdalenost)
                        {
                            break;
                        }
                    }
                    if (p.vzdalenost > maxVzdalenost)
                    {
                        maxVzdalenost = p.vzdalenost;
                    }
                }
            }
            vystup[a] = maxVzdalenost;
        }
        for (int a = 0 ; a < pocetTestu ; a++)
        {
            Console.WriteLine(vystup[a]);
        }
    }
    */
#endregion


namespace HoriciPapir
{
    class Pole
    {
        public bool hori;
        public int x;
        public int y;   
        public void PridejOkoli(Pole[,] vsechnaPole, Queue<Pole> ohne)
        {
            Pole p;
            try
            {
                p = vsechnaPole[x - 1, y - 1];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                }
            }
            catch { }

            try
            {
                p = vsechnaPole[x, y - 1];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                }
            }
            catch { }

            try
            {
                p = vsechnaPole[x + 1, y - 1];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                } 
                
            }
            catch { }

            try
            {
                p = vsechnaPole[x - 1, y];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                }
            }
            catch { }

            try
            {
                p = vsechnaPole[x + 1, y];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                }
            }
            catch { }
 

            try
            {
                p = vsechnaPole[x - 1, y + 1];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                }
            }
            catch { }

            try
            {
                p = vsechnaPole[x, y + 1];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                }
            }
            catch { }

            try
            {
                p = vsechnaPole[x + 1, y + 1];
                if (!p.hori)
                {
                    ohne.Enqueue(p);
                    p.hori = true;
                }
            }
            catch { }
        }
    }

    class Program
    {
        private delegate int ToInt(string s); 

        static void Main(string[] args)
        {
            ToInt ToInt = Convert.ToInt32;
            int pocetTestu = ToInt(Console.ReadLine());
            int[] vystup = new int[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                string[] s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int sirka = ToInt(s[0]);
                int vyska = ToInt(s[1]);
                int pocetOhnu = ToInt(s[2]);
                Pole[,] policka = new Pole[sirka,vyska];
                for (int x=0 ;x<sirka ; x++)
                {
                    for (int y=0 ;y<vyska ; y++)
                    {
                        policka[x, y] = new Pole() { x = x, y = y, hori = false };
                    }
                }
                Queue<Pole> ohne = new Queue<Pole>();  
                for (int i =0 ;i<pocetOhnu ; i++)
                {
                    s = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                    int x = ToInt(s[0]);
                    int y = ToInt(s[1]);
                    Pole p = new Pole() { x = x, y = y, hori = true };
                    policka[x, y] = p;
                    ohne.Enqueue(p);
                }
                int cas = 0;
                pocetOhnu = 0;
                while (ohne.Count != 0)
                {
                    pocetOhnu = ohne.Count;
                    for (int i =0 ;i<pocetOhnu ; i++)
                    {                         
                        ohne.Dequeue().PridejOkoli(policka, ohne);
                    }
                    cas++;
                }
                vystup[a] = cas-1;
            }                    
            for (int a =0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }
        }
        
    }
}
               