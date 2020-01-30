// SpravnePoradieC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Vyres(int* bojovnik, int* posloupnost, int pocetAkci, int pocetMoznychAkci) {
	int* reseni = new int[pocetAkci];
	int index = 0;
	for (int i = 0; i < pocetMoznychAkci; i++) {
		for (int j = 0; j < pocetAkci; j++) {
			if (posloupnost[i] == bojovnik[j]) {
				reseni[index] = bojovnik[j];
				index++;
			}
		}
	}
	for (int i = 0; i < pocetAkci; i++)
		bojovnik[i] = reseni[i];
	delete reseni;
}

void NalezniSpravnePoradi(vector<int>* zavislosti, vector<int>* umozneni, int* moznaPosloupnost, int pocetMoznychAkci) {
	queue<int> fronta;
	bool* pridano = new bool[pocetMoznychAkci + 1];
	for (int i = 1; i < pocetMoznychAkci; i++) {
		if (zavislosti[i].empty()) {
			pridano[i] = true;
			fronta.push(i);
			continue;
		}
		pridano[i] = false;
	}
	int index = 0;
	while (index < pocetMoznychAkci) {
		int akce = fronta.front();
		for (int i = 0; i < umozneni[akce].size(); i++) {
			int umoznenyPrvek = umozneni[akce][i];
			if (!pridano[umoznenyPrvek]) {
				bool mozno = true;
				for (int j = 0; j < zavislosti[umoznenyPrvek].size(); j++) {
					if (!pridano[zavislosti[umoznenyPrvek][j]]) {
						mozno = false;
						break;
					}
				}
				if (mozno) {
					fronta.push(umoznenyPrvek);
					pridano[umoznenyPrvek] = true;
				}
			}
		}
		moznaPosloupnost[index] = akce;
		index++;
		fronta.pop();
	}
}



int main() {
	int pocetMoznychAkci, pocetZavislosti, pocetBojovniku;
	cin >> pocetMoznychAkci >> pocetZavislosti >> pocetBojovniku;
	vector<int>* zavislosti = new vector<int>[pocetMoznychAkci + 1];
	vector<int>* umozneni = new vector<int>[pocetMoznychAkci + 1];
	for (int i = 0; i < pocetZavislosti; i++) {
		int akce, podminka;
		cin >> akce >> podminka;
		zavislosti[akce].push_back(podminka);
		umozneni[podminka].push_back(akce);
	}
	int* posloupnost = new int[pocetMoznychAkci];
	NalezniSpravnePoradi(zavislosti, umozneni, posloupnost, pocetMoznychAkci);
	for (int i = 0; i < pocetBojovniku; i++) {
		int pocetAkci;
		cin >> pocetAkci;
		int* bojovnik = new int[pocetAkci];
		for (int i = 0; i < pocetAkci; i++) {
			cin >> bojovnik[i];
		}
		Vyres(bojovnik, posloupnost, pocetAkci, pocetMoznychAkci);
		for (int i = 0; i < pocetAkci; i++) {
			cout << bojovnik[i] << ' ';
		}
		cout << endl;
		delete bojovnik;
	}
	delete[] posloupnost;
	delete[] zavislosti;
	delete[] umozneni;
}

