using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

#region Zadání 

/*
 Kasiopea 2016/2017, Domácí kolo, úloha B: Caesarova šifra
 Zadání(Řešení)

Se skupinou kamarádů jste se vydali na celonoční šifrovací hru.Princip první šifry jste objevili hned - je to známá Caesarova šifra.
Šifrování funguje takto: Zvolíme číslo a každé písmeno v šifrované zprávě posuneme o tolik míst v abecedě. Pokud jsme přešli přes Z, 
začínáme zase od A. Když chceme zašifrovat text „AHOJ ZUZI“ a zvolíme číslo 4, výsledek bude „ELSN DYDM“. V celé úloze se vyskytují 
jen velká písmena anglické abecedy (tj. 26 písmen bez háčků a čárek, neobsahuje ch).                                        
V tomto případe navíc víte, že se odesílatel zprávy na jejím konci podepsal.Tato znalost se vám může hodit při řešení šifry.

Tvar vstupu                                                                             
Na prvním řádku vstupního souboru je číslo T, počet zašifrovaných dopisů.Pro každý dopis dostanete na prvním řádku číslo N, počet slov 
v dopisu (včetně podpisu). Na dalším řádku následuje N slov oddělených mezerami. Slova se skládají z velkých písmen anglické 
abecedy - A, B, C, ..., Y, Z.Posledním slovem je vždy „CAESAR“, ale v zašifrované podobě. V lehké verzi navíc platí, že všechna 
písmena jsou posunuta o 4 místa vpřed.

Tvar výstupu                        
Pro každý dopis vypište na samostatnou řádku rozluštěný dopis.

Lehká verze             
T ≤ 5
Počet znaků včetně mezer ve zprávě nepřesáhne 250. Posun je vždy o 4 písmena.

Těžká verze    
T ≤ 15
Počet znaků včetně mezer ve zprávě nepřesáhne 500.

Ukázkový vstup  
3
8
DHVEZMQ XI QCWPMQ DI FVYXYW RIGS TPERYNI GEIWEV
9
ELSN ZWIGLRC GIWXC ZIHSY HS QILS WPEZRILS VMQE GEIWEV
4
S DI LBEDO MKOCKB

Ukázkový výstup    
ZDRAVIM TE MYSLIM ZE BRUTUS NECO PLANUJE CAESAR
AHOJ VSECHNY CESTY VEDOU DO MEHO SLAVNEHO RIMA CAESAR
I TY BRUTE CAESAR
*/

#endregion

namespace CaesarovaSifra
{
    class Program
    {
        static void Main(string[] args)
        {
            int pocetTestu = Convert.ToInt32(Console.ReadLine());
            string[] vystup = new string[pocetTestu];
            for (int a =0 ;a<pocetTestu ; a++)
            {
                int pocetSlov = Convert.ToInt32(Console.ReadLine());
                string[] nactenyDopis = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                int posunuti = ( nactenyDopis[pocetSlov - 1][0] -  'C');
                string[] prelozenyDopis = new string[pocetSlov];
                for (int i = 0 ; i < pocetSlov ; i++) 
                {
                    byte ciselnykod;                                            
                    for (int j = 0 ; j < nactenyDopis[i].Length ; j++) 
                    {
                        ciselnykod = (byte) nactenyDopis[i][j];
                        ciselnykod -= (byte) posunuti;
                        if (ciselnykod > (byte) 'Z')
                        {
                            ciselnykod = (byte) ((byte) 'A' + (byte) ciselnykod - (byte) 'Z' - (byte) 1);
                        }
                        if (ciselnykod < (byte) 'A')
                        {
                            ciselnykod = (byte) ((byte) 'Z' - ((byte) 'A' - ciselnykod)+1);
                        }
                        vystup[a] += (char) ciselnykod;
                    }
                    vystup[a] += " ";
                    
                }    
            }
            for (int a =0 ;a<pocetTestu ; a++)
            {
                Console.WriteLine(vystup[a]);
            }
        }
    }
}
