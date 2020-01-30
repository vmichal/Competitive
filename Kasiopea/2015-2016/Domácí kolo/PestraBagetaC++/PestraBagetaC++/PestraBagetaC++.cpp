// PestraBagetaC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void Solve() {
	int pocetPrisad;
	std::cin >> pocetPrisad;
	int** prisady = (int**)malloc(pocetPrisad * sizeof(int*));	  
	for (int i = 0; i < pocetPrisad; i++) {
		prisady[i] = (int*)malloc(2 * sizeof(int));
		std::cin >> prisady[i][0] >> prisady[i][1];
	}  
	int maxPocetPrisad = 0;
	int prisadyZde;
	int pozice;
	for (int i = 0; i < pocetPrisad; i++) {
		pozice = prisady[i][0];
		prisadyZde = 0;
		for (int j = 0; j < pocetPrisad; j++) {
			if (prisady[j][0] <= pozice && prisady[j][1] >= pozice) {
				prisadyZde++;				
			}
		}
		if (prisadyZde > maxPocetPrisad) {
			maxPocetPrisad = prisadyZde;
		}
	}
	std::cout << maxPocetPrisad << "\n";
	for (int i = 0; i < pocetPrisad; i++) {
		free(prisady[i]);
	}
	free(prisady);
}


int main()
{
	int pocetTestu;
	std::cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		Solve();
	}
}

