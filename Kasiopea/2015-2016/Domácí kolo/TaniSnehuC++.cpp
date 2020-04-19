#include "stdafx.h"
#include <iostream>

using namespace std;

void Solve() {
	int n;
	cin >> n;
	int *hromada = new int[n];
	int* zacatek = hromada,
		*konec = hromada + n;
	int vstup, minula = 0;
	while (zacatek != konec) {
		cin >> vstup;
		if (vstup > minula + 1) 
			*zacatek = minula + 1;
		else 
			*zacatek = vstup;
		minula = *zacatek;
		zacatek++;
	}
	zacatek = hromada;
	konec--;
	minula = 0;
	int nejdelsiCas = 0;
	while (konec >= zacatek) {
		if (*konec >= minula+1) {
			*konec = minula+1;
			if (*konec > nejdelsiCas) {	
				nejdelsiCas = *konec;
			}
		}
		minula = *konec;
		konec--;
	}
	cout << nejdelsiCas << endl;
	delete[] hromada;
}

int main() {
	int pocetTestu;
	cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++)
		Solve();
	return 0;
}