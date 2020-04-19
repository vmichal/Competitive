// Postak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void Solve() {
	int N;
	cin >> N;
	int *cislaLodi = new int[N], 
		*lod = cislaLodi, 
		*konec = cislaLodi + N;
	while (lod != konec) {
		cin >> *lod;
		lod++;
	}
	int maxVzdalenost = 0;
	int dopis = 1;
	lod = cislaLodi;
	int *lod1 = lod + 1,
		*lod2 = lod + 2;
	while (lod2 != konec) {
		int vzdalenost = abs(*lod - *lod1) + abs(*lod1 - *lod2);
		int vzdalenostPriVypusteni = abs(*lod - *lod2);
		int rozdil = vzdalenost - vzdalenostPriVypusteni;
		if (rozdil > maxVzdalenost) {
			maxVzdalenost = rozdil;
			dopis = lod1 - cislaLodi;
		}
		lod++; lod1++; lod2++;
	}
	cout << dopis << endl;
	delete[] cislaLodi;	
}	

int main()
{
	int pocetTestu;
	cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		Solve();
	}
    return 0;
}

