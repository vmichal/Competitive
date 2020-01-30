// CaesarovaSifraC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void Solve() {
	int pocetSlov;
	std::cin >> pocetSlov;
	char* zprava = (char*)malloc(500 * sizeof(char));
	char znak;
	int pocitadlo = 0;
	while (znak != '\n' && pocitadlo<500) {
		zprava[pocitadlo] = znak;
		pocitadlo++;
	}
	for (int i = 0; i < pocitadlo; i++) {
		std::cout << zprava[i];
	}
}

int main()
{
	int pocetTestu;
	std::cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		Solve();
	}
}

