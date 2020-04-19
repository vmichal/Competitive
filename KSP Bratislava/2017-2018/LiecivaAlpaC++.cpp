                 
#include "stdafx.h"
#include <iostream>
                  
using namespace std;

int main()
{
	int pocetBojovniku, pocetKapek;
	cin >> pocetBojovniku >> pocetKapek;
  int* bojovnici = new int[pocetBojovniku];
  for (int i = 0;i<pocetBojovniku;i++) {
    cin >> bojovnici[i];
  }

  long celkovySoucet = 0, pocetZraneni;
  int  maximum = 0; 
  
  for (int i = pocetBojovniku-1;i>= 0;i--){
    celkovySoucet += bojovnici[i];
    pocetZraneni = celkovySoucet;
    int index = pocetBojovniku-1;
    while (pocetZraneni % pocetKapek != 0){
      pocetZraneni -= bojovnici[index];
      index--;
    }
    int vysledek = index-i+1;
    if (vysledek > maximum)
      maximum = vysledek;    
  }
  
  
	cout << maximum << endl;
  delete[] bojovnici;
}