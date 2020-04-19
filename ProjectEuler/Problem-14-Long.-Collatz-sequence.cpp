//https://projecteuler.net/problem=14

/*The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.*/


#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAX 1000000	

long long *vzdalenostiDoKonce;

void InicializujPole() {
	vzdalenostiDoKonce = new long long[MAX];
 	for (int i = 0; i < MAX; i++) 
		vzdalenostiDoKonce[i] = -1;

	for (int i = 0; pow(2, i) < MAX; i++) 
		vzdalenostiDoKonce[(int)pow(2, i)] = i+1;
}

void VypoctiVzdalenost(long long i) {
	long long cislo = i, pocetClanku = 0;
	bool konec = false;

	//cout << cislo;
	while (true) {
		if (cislo < MAX && vzdalenostiDoKonce[cislo] != -1) {
			pocetClanku += vzdalenostiDoKonce[cislo];
			//cout << "("<<vzdalenostiDoKonce[cislo] << ")";
			konec = true;
		}
		else 
			pocetClanku++;
		cislo = (cislo % 2 == 0) ? (cislo / 2) : (cislo * 3 + 1);
		if (konec)
			break;
		//cout << " => " << cislo;
	}

	while (i != cislo) {
		if (i < MAX)
			vzdalenostiDoKonce[i] = pocetClanku;
		pocetClanku--;
		i = (i % 2 == 0) ? (i / 2) : (i * 3 + 1);
	}
}


int main() {				  
	InicializujPole();	

	for (int i = 1; i < MAX; i++) {
		VypoctiVzdalenost(i);
		//cout << vzdalenostiDoKonce[i] << endl;
	}		

	int nejdelsi = 0;
	for (int i = 1; i < MAX; i++) {
		if (vzdalenostiDoKonce[i] > vzdalenostiDoKonce[nejdelsi])
			nejdelsi = i;
	}
	cout << nejdelsi << " s počtem kroků:" << vzdalenostiDoKonce[nejdelsi] << endl;
	delete[] vzdalenostiDoKonce;
}

