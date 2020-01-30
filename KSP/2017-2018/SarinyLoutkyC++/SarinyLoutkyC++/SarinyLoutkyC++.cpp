// SarinyLoutkyC++.cpp : Defines the entry point for the console application.
//					 

#include "stdafx.h"	 
#include <iostream>

int main()
{
	int pocetLoutek, maxHmotnost, pivot;
	std::cin >> pocetLoutek >> maxHmotnost;
	int* loutky = (int*) malloc(pocetLoutek * sizeof(int));
	for (int i = 0; i < pocetLoutek; i++) {
		std::cin >> loutky[i];
	}
	bool pokracovat;
	for (int i = 0; i < pocetLoutek; i++) {
		pokracovat = false;
		for (int j = 0; j < pocetLoutek-1; j++) {
			pivot = loutky[j];
			loutky[j] = loutky[j + 1];							 
			loutky[j + 1] = pivot;
			pokracovat = true;
		}
		if (!pokracovat) {
			break;
		}
	}
	int zacatek = 0, konec = pocetLoutek - 1, pocetVesaku = 0;
	while (zacatek <= konec) 
	{
		if (loutky[konec] + loutky[zacatek] <= maxHmotnost) {
			zacatek++;
		}
		konec--;
		pocetVesaku++;
	}
	free(loutky);
	std::cout << pocetVesaku;  
}