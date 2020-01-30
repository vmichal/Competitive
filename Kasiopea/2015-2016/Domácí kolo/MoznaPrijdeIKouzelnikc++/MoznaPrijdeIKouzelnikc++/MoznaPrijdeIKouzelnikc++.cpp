// MoznaPrijdeIKouzelnikc++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>



/*
	int pocetKraliku, pocetMavnuti, pocetPozic;
	std::cin >> pocetKraliku >> pocetMavnuti >> pocetPozic;
	int* kralici = (int*)malloc(sizeof(int)*pocetKraliku);
	int nacteno, prohozeni = 0, otoceni = 0;
	for (int j = 0; j < pocetMavnuti; j++) {
		std::cin >> nacteno;
		if (nacteno == 1) {
			otoceni++;
		}
		if (nacteno == 2) {
			prohozeni++;
		}
	}
	if (prohozeni % 2 == 1) {
		int pivot = kralici[0];
		kralici[0] = kralici[1];
		kralici[1] = pivot;
	}
	if (otoceni % 2 == 1) {
		int* pomocnePole = (int*)malloc(sizeof(int)* pocetKraliku);
		for (int x = 0; x < pocetKraliku; x++) {
			pomocnePole[pocetKraliku - x - 1] = kralici[x];
		}
		for (int x = 0; x < pocetKraliku; x++) {
			kralici[x] = pomocnePole[x];
		}
		free(pomocnePole);
	}
	int pozice;
	for (int j = 0; j < pocetPozic; j++) {
		std::cin >> pozice;
		std::cout << kralici[pozice] << " ";
	}
	std::cout << "\n";	  */

/*�e�en� s popisem*/
/*void SolveOne() {
	int pocetKraliku, pocetMavnuti, pocetPozic;
	std::cin >> pocetKraliku >> pocetMavnuti >> pocetPozic;
	int* kralici = (int*)malloc(pocetKraliku * sizeof(int));
	std::cout << "Byl inicializov�n ukazatel kr�l�ci na blok pam�ti s " << pocetKraliku << " prvky.\n";
	int cisloKralika;
	std::cout << "Jednotliv� ��sla kr�l�k�: \n";
	for (int i = 0; i < pocetKraliku; i++) {
		std::cin >> cisloKralika;
		kralici[i] = cisloKralika;
		std::cout << cisloKralika << " ";
	}
	std::cout << "\nNa�ten blok kr�l�k� s ��sly:\n";
	for (int i = 0; i < pocetKraliku; i++) {
		std::cout << kralici[i] << " ";
	}
	int vsichni = 0, prvni = 0;
	std::cout << "\nVytvo�eny prom�nn� vsichni a prvni s hondotami " << vsichni << " "<< prvni<< "\n";
	int kouzlo;
	for (int i = 0; i < pocetMavnuti; i++) {
		std::cin >> kouzlo;
		std::cout << kouzlo << " ";
		if (kouzlo == 1) {
			vsichni++;
		}
		else if (kouzlo == 2) {
			prvni++;
		}
		else{
			std::cout << "Chyba p�i na��t�n�.";
		}
	}
	int* pozice = (int*)malloc(pocetPozic*sizeof(int));
	std::cout << "\nVytvo�eno pole pozic s " << pocetPozic << " prvky.\n";
	for (int i = 0; i < pocetPozic; i++) {
		std::cin >> pozice[i];
		std::cout << pozice[i] << " ";
	}				
	std::cout << "\nJe�t� jednou pole kr�l�k�:\n";
	for (int i = 0; i < pocetKraliku; i++) {
		std::cout << kralici[i] << " ";
	}
	int pivot = kralici[0];
	kralici[0] = kralici[pocetKraliku - 1];
	kralici[pocetKraliku - 1] = pivot;
	std::cout << "\nPo prohozen� prvn�ho a posledn�ho:\n";
	for (int i = 0; i < pocetKraliku; i++) {
		std::cout << kralici[i] << " ";
	}
	int* pomocnePole = (int*)malloc(pocetKraliku * sizeof(int));
	for (int i = 0; i < pocetKraliku; i++) {
		pomocnePole[i] = kralici[pocetKraliku - 1 - i];
	}
	for (int i = 0; i < pocetKraliku; i++) {
		kralici[i] = pomocnePole[i];
	}
	std::cout << "\nPo oto�en� pole:\n";
	for (int i = 0; i < pocetKraliku; i++) {
		std::cout << kralici[i] << " ";
	}
	std::cout << "\nKr�l�ci na indexech v prvn� �ad� jsou ve druh� �ad�.\n";
	for (int i = 0; i < pocetPozic; i++) {
		std::cout << pozice[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < pocetPozic; i++) {
		std::cout << kralici[pozice[i]-1] << " ";
	}
	std::cout << "\n\n\n\n";
}*/

void SolveOne() {
	int pocetKraliku, pocetMavnuti, pocetPozic;
	std::cin >> pocetKraliku >> pocetMavnuti >> pocetPozic;
	int* kralici = (int*)malloc(pocetKraliku * sizeof(int));
	int cisloKralika;
	for (int i = 0; i < pocetKraliku; i++) {
		std::cin >> cisloKralika;
		kralici[i] = cisloKralika;
	}
	int vsichni = 0, prvni = 0;
	int kouzlo;
	for (int i = 0; i < pocetMavnuti; i++) {
		std::cin >> kouzlo;
		if (kouzlo == 1) {
			vsichni++;
		}
		if (kouzlo == 2) {
			prvni++;
		}
	}			
	if (prvni % 2 == 1) {
		int pivot = kralici[0];
		kralici[0] = kralici[pocetKraliku - 1];
		kralici[pocetKraliku - 1] = pivot;
	}
	if (vsichni % 2 == 1) {
		int* pomocnePole = (int*)malloc(pocetKraliku * sizeof(int));
		for (int i = 0; i < pocetKraliku; i++) {
			pomocnePole[i] = kralici[pocetKraliku - 1 - i];
		}
		for (int i = 0; i < pocetKraliku; i++) {
			kralici[i] = pomocnePole[i];
		}
		free(pomocnePole);
	}
	int pozice;
	for (int i = 0; i < pocetPozic; i++) {
		std::cin >> pozice;
		std::cout << kralici[pozice - 1] << " ";
	}
	std::cout << "\n";
	free(kralici);
}

int main()
{
	int pocetTestu;
	std::cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		SolveOne();
	}
}

