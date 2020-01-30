// DuchodciC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int NajdiNejrychlejsiho(int* nenavidene, int* rychlost, int pocet, int kanal) {
	int pocetNenavidicich = 0;
	int* nenavidici = new int[pocet];
	for (int i = 0; i < pocet; i++) {
		if (nenavidene[i] == kanal) {
			nenavidici[pocetNenavidicich] = i;
			pocetNenavidicich++;
		}
	}
	int nejrychlejsi = 0;
	for (int i = 1; i < pocetNenavidicich; i++) {
		if (rychlost[nenavidici[i]] > rychlost[nenavidici[nejrychlejsi]]) {
			nejrychlejsi = i;
		}
	}
	return nenavidici[nejrychlejsi];
}
int Solve() {
	int pocetDuchodcu, kanal;
	std::cin >> pocetDuchodcu >> kanal;
	int* oblibeneKanaly = new int[pocetDuchodcu];
	int* nenavideneKanaly = new int[pocetDuchodcu];
	int* rychlost = new int[pocetDuchodcu];
	bool* prepnul = new bool[pocetDuchodcu];
	for (int i = 0; i < pocetDuchodcu; i++) {
		std::cin >> nenavideneKanaly[i] >> oblibeneKanaly[i] >> rychlost[i];
		prepnul[i] = false;
	}
	while (true) {
		int nejrychlejsi = NajdiNejrychlejsiho(nenavideneKanaly, rychlost, pocetDuchodcu, kanal);
		if (nejrychlejsi == -1) {
			return kanal;
		}
		kanal = oblibeneKanaly[nejrychlejsi];
		if (prepnul[nejrychlejsi]) {
			return -1;
		}
		prepnul[nejrychlejsi] = true;
	}									 
	delete oblibeneKanaly;
	delete nenavideneKanaly;
	delete rychlost;
	delete prepnul;
}

int main()
{
	int pocetTestu;
	std::cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		std::cout << Solve() << '\n';
	}
}

