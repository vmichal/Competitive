//https://projecteuler.net/problem=20

/*Find the sum of the digits in the number 100!*/


#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct Cislo {

	vector<int> cislice;

	Cislo() {
		cislice.push_back(1);
	}

	void nasob(int cinitel) {
		int carry = 0;
		for (int i = 0; i < cislice.size(); i++) {
			cislice[i] = cislice[i] * cinitel + carry;
			carry = cislice[i] / 10;
			cislice[i] %= 10;  
		}
		while (carry != 0) {
			cislice.push_back(carry % 10);
			carry /= 10;
		}				
	}				   

	int vypisSoucet() {
		int soucet = 0;
		for (int i = cislice.size() - 1; i >= 0; i--) {
			soucet += cislice[i];
		}
		return soucet;
	}
};



int main() {
	Cislo cislo;
	for (int i = 2; i <= 100; i++) 
		cislo.nasob(i);	  	
	cout << cislo.vypisSoucet() << endl;
    return 0;
}

