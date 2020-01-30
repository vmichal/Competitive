using System;
using System.Collections.Generic;
using System.IO;

public class Tridic
{
	static void Main(string[] args)
    {
        int pocetPrvku = int.Parse(Console.ReadLine());
        int[] pole = new int[pocetPrvku];
        for (int i = 0 ;i<pocetPrvku ; i++)
        {
            pole[i] = int.Parse(Console.ReadLine());
        }
        int pivot;
        bool next;
        for (int i = 0 ;i<pocetPrvku ; i++)
        {
            next = false;
            for (int j =0 ;j<pocetPrvku-1 ; j++)
            {
                if (pole[j] > pole[j + 1])
                {
                    pivot = pole[j];
                    pole[j] = pole[j + 1];
                    pole[j + 1] = pivot;
                    next = true;
                }
            }
            if (!next)
            {
                break;
            }
        }
        for (int i = 0 ;i<pocetPrvku ; i++)
        {
            Console.WriteLine(pole[i]);
        }                              
    }
}
                     