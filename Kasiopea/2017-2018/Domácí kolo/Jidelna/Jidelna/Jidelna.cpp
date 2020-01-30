#include "stdafx.h"
#include <iostream>

using namespace std;

unsigned long VypoctiJidelnu(int **jidelnaX, int *jidelnaY, int **pole, int X, int Y) {
	int **ptrX = pole,
		**konecX = pole + X,
		*ptrY,
		*konecY,
		*zacatekY;
	unsigned long vzdalenost = 0;
	while (ptrX != konecX) {
		zacatekY = *ptrX;
		ptrY = zacatekY;
		konecY = zacatekY + Y;
		while (ptrY != konecY) {
			vzdalenost += *ptrY * (abs(jidelnaX - ptrX) + abs((jidelnaY-*jidelnaX)-(ptrY-zacatekY)));
			ptrY++;
		}			
		ptrX++;
	}
	return vzdalenost;
}

unsigned long VypoctiVystup(int Y, int X, int **pole) {
	unsigned long minVzdalenost = UINT64_MAX;
	int **ptrX = pole,
		**konecX = pole + X,
		*ptrY,
		*konecY;
	while (ptrX != konecX) {
		ptrY = *ptrX;
		konecY = ptrY + Y;
		while (ptrY != konecY) {
			unsigned long vzdalenost = VypoctiJidelnu(ptrX, ptrY, pole, X, Y);
			cout << "Vypoètena vzdálenost " << vzdalenost << endl;
			if (vzdalenost < minVzdalenost) {
				minVzdalenost = vzdalenost;
				cout << "Nové minimum  " << minVzdalenost << endl;
			}
			ptrY++;
		}	
		ptrX++;
	}



	return minVzdalenost;
}

void Solve() {
	int Y, X;
	cin >> Y >> X;
	int **pole = new int*[X],
		**konecX = pole + X,
		**ptrX = pole;
	while (ptrX != konecX) {	  
		*ptrX = new int[Y];
		ptrX++;
	}
		
	for (int y = 0; y < Y; y++) {
		ptrX = pole;
		while (ptrX != konecX) {
			cin >> *((*ptrX) + y);
			ptrX++;
		}
	}
	cout << VypoctiVystup(Y, X, pole) << endl;
	ptrX = pole;
	while (ptrX != konecX) {
		delete[] *ptrX;
		ptrX++;
	}
	delete[] pole;
}

int main()
{
	int pocetTestu;
	cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		Solve();
	}
	_beep(50, 100);
	return 0;
}	