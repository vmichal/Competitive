// https://projecteuler.net/problem=25

/*The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

struct Cislo {
	vector<int> cislice;

	Cislo() {}

	Cislo(int hodnota) {
		cislice.push_back(hodnota % 10);
	}

	static Cislo secti(Cislo const a, Cislo const b) {
		int carry = 0;
		Cislo vysledek;
		Cislo const & mensi = (a.cislice.size() < b.cislice.size()) ? a : b,
			  & delsi = (a.cislice.size() < b.cislice.size()) ? b : a;
		for (int i = 0; i < mensi.cislice.size(); i++) {
			int soucet = carry + a.cislice[i] + b.cislice[i];
			carry = soucet / 10;
			vysledek.cislice.push_back(soucet % 10);
		}
		for (int i = mensi.cislice.size(); i < delsi.cislice.size(); i++) {
			int soucet = carry + delsi.cislice[i];
			carry = soucet / 10;
			vysledek.cislice.push_back(soucet % 10);
		}
		if (carry != 0)
			vysledek.cislice.push_back(carry);
		return vysledek;
	}

	void vypis() {
		for (int i = cislice.size() - 1; i >= 0; i--) {
			cout <<cislice[i];
		}
	}
};


int main() {
	Cislo a(1), b(2);

	for (int i = 4; i < INT_MAX; i++) {
		Cislo c = Cislo::secti(a, b);
		a = b;
		b = c;
		if (c.cislice.size() == 1000) {
			cout << i <<"\t" << c.cislice.size() << endl;
			break;
		}		
	}			  
    return 0;
}

