// HoriciPapirC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int** papir;
int** ohne;
int* konec;	
int* cas;
int sirka, vyska, pocetOhnu;

void Pridej(int posledniCas, int x, int y) {
	*konec = *konec + 1;
	ohne[*konec][0] = x;
	ohne[*konec][1] = y;
	papir[x][y] = posledniCas+1;
}

void NajdiPolicka(int* aktualniOhen) {
	int x = aktualniOhen[0];
	int y = aktualniOhen[1];
	int hori = papir[x][y];
	if (hori > *cas) {
		*cas = hori;
	}
	if (x > 0) {
		if (papir[x - 1][y] == INT_MAX) {
			Pridej(hori, x - 1, y);
		}
		if (y > 0) {
			if (papir[x - 1][y - 1] == INT_MAX) {
				Pridej(hori, x - 1, y - 1);
			}
		}
		if (y < vyska - 1) {
			if (papir[x - 1][y + 1] == INT_MAX) {
				Pridej(hori, x - 1, y + 1);
			}
		}
	}							  
	if (y > 0) {
		if (papir[x][y - 1] == INT_MAX) {
			Pridej(hori, x, y - 1);
		}
	}
	if (y < vyska - 1) {
		if (papir[x][y + 1] == INT_MAX) {
			Pridej(hori, x, y + 1);
		}
	}							  
	if (x < sirka - 1) {
		if (papir[x + 1][y] == INT_MAX) {
			Pridej(hori, x + 1, y);
		}	
		if (y > 0) {
			if (papir[x + 1][y - 1] == INT_MAX) {
				Pridej(hori, x + 1, y - 1);
			}
		}
		if (y < vyska - 1) {
			if (papir[x + 1][y + 1] == INT_MAX) {
				Pridej(hori, x + 1, y + 1);
			}
		}
	}										
}


void Solve() {
	std::cin >> sirka >> vyska >> pocetOhnu;
	papir = (int**)malloc(sirka*(sizeof(int*)));
	for (int i = 0; i < sirka; i++) {
		papir[i] = (int*)malloc(vyska * sizeof(int));
		for (int j = 0; j < vyska; j++) {
			papir[i][j] = INT_MAX;
		}
	}
	int pocetCtverecku = sirka*vyska;
	ohne = (int**)malloc(pocetCtverecku * sizeof(int*));
	for (int i = 0; i < pocetCtverecku; i++) {
		ohne[i] = (int*)malloc(2 * sizeof(int));
	}
	char** ohnicky = (char**)malloc(sirka * sizeof(char*));
	for (int i = 0; i < pocetOhnu; i++) {	
		int x,y;
		std::cin >> x >> y;
		papir[x][y] = 0;
		ohne[i][0] = x;
		ohne[i][1] = y;
	}
	int zacatek = 0;
	*cas = 0;
	*konec = pocetOhnu - 1;
	while (zacatek <= *konec) {
		NajdiPolicka(ohne[zacatek]);
		zacatek++;
	}
	free(papir);
	free(ohne);
	std::cout << *cas << "\n";
}


int main()
{
	konec = new int;
	cas = new int;
	int pocetTestu;
	std::cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		Solve();
	}
	delete konec;
	delete cas;
}				  