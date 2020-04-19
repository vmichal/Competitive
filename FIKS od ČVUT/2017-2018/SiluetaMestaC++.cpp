#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct Budova {
	int vyska, levy, pravy;
	Budova *dalsi, *predchozi;

	Budova* PripojZa(Budova* budova) {
		budova->dalsi = this;
		predchozi = budova;
		return this;
	}

	Budova* PripojPred(Budova* budova) {
		budova->predchozi = this;
		dalsi = budova;
		return this;
	}

	void PripojMezi(Budova* vyssi) {
		Budova* nizsi = vyssi->predchozi;
		nizsi->dalsi = this;
		dalsi = vyssi;
		vyssi->predchozi = this;
		predchozi = nizsi;
	}

	unsigned long PrictiBudovu() {
		return vyska*(pravy - levy);
	}
};

void UpravBudovy(Budova *aktualni, vector<Budova*>* budovy) {
	Budova *dalsi = aktualni->dalsi;
	while (dalsi) {
		if (aktualni->pravy >= dalsi->pravy) {
			if (aktualni->vyska >= dalsi->vyska) {
				aktualni->dalsi = dalsi->dalsi;
				aktualni->dalsi->predchozi = aktualni;
				goto Dalsi;
			}
			else {

			}
		}

	Dalsi:
		aktualni = aktualni->dalsi;
	}


		   
}

void NactiASetrid(Budova** pr, Budova** po, vector<Budova*>* budovy) {
	Budova *b = new Budova();
	budovy->push_back(b);
	cin >> b->vyska >> b->levy >> b->pravy;
	Budova *prvni = *pr, *posledni = *po;
	if (b->levy <= prvni->levy) {  //Pokud bude nová budova první	
		*pr = b->PripojPred(prvni);
		return;
	}
	Budova *budova = prvni;
	while (true) {  //Dokud následuje další budova
		if (budova->levy >= b->levy) {
			b->PripojMezi(budova);
			return;
		}
		if (budova->dalsi) {
			budova = budova->dalsi;
			continue;
		}
		break;
	}
	*po = b->PripojZa(*po);
	return;
}

void Solve() {
	int pocetBudov;
	cin >> pocetBudov;
	Budova *prvni, *posledni, *aktualni;
	vector<Budova*> budovy;
	prvni = new Budova();
	budovy.push_back(prvni);
	cin >> prvni->vyska >> prvni->levy >> prvni->pravy;
	for (int i = 1; i < pocetBudov; i++) 
		NactiASetrid(&prvni, &posledni, &budovy);
	unsigned long obsah = 0;
	aktualni = prvni;
	UpravBudovy(prvni, &budovy);
	while (aktualni) {
		obsah += aktualni->PrictiBudovu();
		aktualni = aktualni->dalsi;
	}
	for (int i = 0; i<budovy.size(); i++) {
		if (budovy[i]) {
			delete budovy[i];
		}
	}
	budovy.~vector();
	cout << obsah << endl;
}

int main()
{
	int pocetVstupu;
	cin >> pocetVstupu;							  
	for (int i = 0; i < pocetVstupu-8; i++) {
		Solve();
	}
}