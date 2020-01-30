		   
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int pocetZahradek, delkaTrvaniNapoje;
	cin >> pocetZahradek >> delkaTrvaniNapoje;
	int* zahradky = new int[pocetZahradek];
	for (int i = 0; i < pocetZahradek; i++)
		cin >> zahradky[i];
	int* casy = new int[pocetZahradek];
	for (int i = 0; i < pocetZahradek; i++) {
		cin >> casy[i];
		if (casy[i] < zahradky[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	int zbylyCas = 0, pocetLektvaru = 0;
	for (int i = 0; i < pocetZahradek; i++) {
		if (zahradky[i] <= zbylyCas) {
			zbylyCas -= zahradky[i];
			continue;
		}
		zahradky[i] -= zbylyCas;
		casy[i] -= zbylyCas;
		zbylyCas = 0;
		while (casy[i] < zahradky[i] * 2 && zahradky[i] > 0) {
			pocetLektvaru++;
			zahradky[i] -= delkaTrvaniNapoje;
			casy[i] -= delkaTrvaniNapoje;
		}
		if (zahradky[i] < 0)
			zbylyCas = -zahradky[i];
	}
	cout << pocetLektvaru << endl;
	delete[] zahradky;
	delete[] casy;
}

