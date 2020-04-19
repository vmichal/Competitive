#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
   /*				  
#include <algorithm>
void flip(int *pole, int cislo) {
	int *pom = new int[cislo];
	for (int i = 0; i < cislo; i++) {
		pom[cislo - i-1] = pole[i];
	}
	memcpy(pole, pom, cislo * 4);
}

unsigned ZjistiPocetOperaci(int *pole) {
	unsigned pocetProhozeni = 0;
	while (*pole != 1) {
		flip(pole, *pole);
		pocetProhozeni++;
		if (pocetProhozeni == 750) {	 
			cout << "Pøíliš mnoho prohození";
			break;
		}
	}	
	return pocetProhozeni;
}

int main()
{	
	int n;
	cin >> n;
	int *pole = new int[n];
	int *nejdelsi = new int[n];
	int *pomocnePole = new int[n];
	for (int i = 0; i < n; i++)
		pole[i] = i+1;	 
	unsigned pocetOperaci = 0;
	int velikost = n * 4;
	do {
		memcpy(pomocnePole, pole, velikost);
		unsigned pom = ZjistiPocetOperaci(pomocnePole);
		if (pom > pocetOperaci) {
			memcpy(nejdelsi, pole, velikost);
			pocetOperaci = pom;
			cout << "Nový nejdelší poèet operací " << pocetOperaci << endl;
			if (pocetOperaci >= 750) {
				cout << "Dosaženo 750 operací" << endl;
				break;
			}
		}					   		
	} while (next_permutation(pole, pole + n));
	cout << "\n\nNejdelší permutace vyžaduje " << pocetOperaci << " operací." << endl;
	for (int i = 0; i < n; i++) {
		cout << nejdelsi[i] << " ";
	}
	cout << endl;
	delete[] pole;
	delete[] nejdelsi;
	delete[] pomocnePole;
	return 0;
}*/		

void flip(int *pole) {
	const int cislo = *pole;
	int* pomocna = new int[cislo];
	for (int i = cislo - 1; i >= 0; i--) {
		pomocna[cislo - i - 1] = pole[i];
	}
	for (int i = 0; i < cislo; i++) {
		pole[i] = pomocna[i];
	}
	delete[] pomocna;
}

unsigned ZjistiPocetOperaci(int *pole) {
	unsigned pocetProhozeni = 0;
	while (*pole != 1) {
		flip(pole);
		pocetProhozeni++;
		if (pocetProhozeni == 750) {
			cout << "Dostatek prohození";
			break;
		}
	}
	return pocetProhozeni;
}

int main() {	 
	int n;
	cin >> n;
	int *pole = new int[n];
	for (int i = 0; i < n; i++) {
		pole[i] = i + 1;
	}
	cout << endl;
	int pocetOperaci = 0;
	while (true) {
		random_shuffle(pole, pole + n);
		unsigned pom = ZjistiPocetOperaci(pole);
		if (pom >= 750) {
			pocetOperaci = pom;
			cout << "Nalezena permutace" << endl;
			break;
		}
	}
	cout << "\n\nNejdelší permutace vyžaduje " << pocetOperaci << " operací." << endl;
	for (int i = 0; i < n; i++) {
		cout << pole[i] << " ";
	}
	cout << endl;
	delete[] pole;
	return 0;
}

