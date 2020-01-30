// RytiriNaDrakaC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void Solve() {
	int pocetHlav, pocetRytiru;
	std::cin >> pocetHlav >> pocetRytiru;
	int* rytiri = (int*)malloc(pocetRytiru * sizeof(int));
	int* hlavy = (int*)malloc(pocetHlav * sizeof(int));
	for (int i = 0; i < pocetHlav; i++) {
		std::cin >> hlavy[i];
	}
	for (int i = 0; i < pocetRytiru; i++) {
		std::cin >> rytiri[i];
	}
	int indexRytiri = 0, indexHlavy = 0;
	long cena = 0;
	while (indexHlavy < pocetHlav && indexRytiri < pocetRytiru) {
		if (hlavy[indexHlavy] <= rytiri[indexRytiri]) {
			cena += rytiri[indexRytiri];
			indexHlavy++;
		}
		indexRytiri++;
	}
	if (indexHlavy == pocetHlav) {
		std::cout << cena << "\n";
	}
	else {
		std::cout << -1 << "\n";
	}
	free(hlavy);
	free(rytiri);
}

int main()
{
	int pocetTestu;
	std::cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		Solve();
	}
    return 0;
}

