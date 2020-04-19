
#include "stdafx.h"
#include <iostream>

using namespace std;

void Solve() {
	int pocetRostlin;
	cin >> pocetRostlin;
	int *rostliny = new int[pocetRostlin];
	int *zacatek = rostliny, 
		*konec = rostliny + pocetRostlin;
	while (zacatek != konec) {
		cin >> *zacatek;
		zacatek++;
	}
	zacatek = rostliny;
	delete[] rostliny;
}	

int main()
{
	int pocetTestu;
	cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++)
		Solve();
    return 0;
}