//https://projecteuler.net/problem=16
/*215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

#define MOCNINA 1000
struct Cislo {
	vector<char> cislice;

	Cislo() {
		cislice.push_back(1);
	}

	void Multiply() {
		char carry = 0;
		for (int i = 0; i < cislice.size(); i++) {
			cislice[i] = cislice[i] * 2 + carry;
			carry = cislice[i] / 10;
			cislice[i] %= 10;
		}
		if (carry == 1)
			cislice.push_back(1);
	}

	unsigned Sum() {
		unsigned soucet = 0;
		for (int i = 0; i < cislice.size(); i++) {
			soucet += cislice[i];
		}
		return soucet;
	}
};


int main() {
	Cislo cislo;

	for (int i = 0; i < MOCNINA; i++) {
		cislo.Multiply();
	}

	cout << cislo.Sum() << endl;


    return 0;
}

