//https://projecteuler.net/problem=48

/*The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#define MAX 1000


using namespace std;

struct Cislo {
	vector<int> cislice;

	Cislo() {}

	Cislo(int hodnota) {
		cislice.push_back(hodnota % 10);   
		hodnota /= 10;
		while (hodnota != 0) {
			cislice.push_back(hodnota % 10);
			hodnota /= 10;
		}
	}

	static Cislo secti(Cislo const *a, Cislo const *b) {
		int carry = 0;
		Cislo vysledek;
		Cislo const * mensi = (a->cislice.size() < b->cislice.size()) ? a : b,
			*delsi = (a->cislice.size() < b->cislice.size()) ? b : a;
		for (int i = 0; i < mensi->cislice.size(); i++) {
			int soucet = carry + a->cislice[i] + b->cislice[i];
			carry = soucet / 10;
			vysledek.cislice.push_back(soucet % 10);
		}
		for (int i = mensi->cislice.size(); i < delsi->cislice.size(); i++) {
			int soucet = carry + delsi->cislice[i];
			carry = soucet / 10;
			vysledek.cislice.push_back(soucet % 10);
		}
		if (carry != 0)
			vysledek.cislice.push_back(carry);
		return vysledek;
	}

	void vynasob(int cinitel) {
		int carry = 0;
		for (int i = 0; i < cislice.size(); i++) {
			int soucet = cislice[i] * cinitel + carry;
			carry = soucet / 10;
			cislice[i] = soucet % 10;
		}
		while (carry != 0) {
			cislice.push_back(carry % 10);
			carry /= 10;
		}
	}
				   
	void vypis() {
		for (int i = cislice.size() - 1; i >= 0; i--) {
			cout << cislice[i];
		}
	}

	Cislo operator +(Cislo b) {
		return secti(this, &b);
	}

};

int main() {
	vector<Cislo> cisla;
	for (int i = 1; i <= MAX; i++) {
		Cislo c(i);
		for (int j = 1; j < i; j++) 
			c.vynasob(i);	
		cisla.push_back(c);		
	}
	Cislo soucet(0);
	for each (Cislo c in cisla)
		soucet = c + soucet;
	soucet.vypis();

    return 0;
}

