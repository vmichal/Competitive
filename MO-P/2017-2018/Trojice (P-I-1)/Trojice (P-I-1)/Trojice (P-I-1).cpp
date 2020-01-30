#include "stdafx.h"	 
#include <iostream>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	long *vstup = new long[n];
	long *prvni = vstup;
	long *posledni = vstup + n-1;
	while (prvni <= posledni) {
		cin >> *prvni;
		prvni++;
	}
	long **a = &vstup,
		**b = a + 1,
		**c = b+1,
		*mezivysledky = new long[3];
	for (int i = 0; i < 3; i++) {
		mezivysledky[i] = **a + **b + **c;
	}
	cout << (**a+**b+**c) << endl;
	delete[] vstup;
	delete[] mezivysledky;
}			 