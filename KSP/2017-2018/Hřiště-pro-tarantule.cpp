// Hřiště pro tarantule.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main() {
	int pocet, kroky;
	std::cin >> pocet >> kroky;
	int *x = new int[pocet], *y = new int[pocet];
	int provedeno = 1;
	for (int i = 0; i < pocet; i++) {
		x[i] = i;
		y[i] = i;
	}			 
	while (kroky-- != 0) {
		for (int i = 0; i < pocet; i++) {
			char znak;
			std::cin >> znak;
			switch (znak) {
				case '^':
					if (y[i] > 0)
						y[i]--;
					break;
				case 'v':
					if (y[i] < pocet - 1)
						y[i]++;
					break;
				case '<':
					if (x[i] > 0)
						x[i]--;
					break;
				case '>':
					if (x[i] < pocet - 1)
						x[i]++;
					break;
			}
		}
		for (int i = 0;i<pocet;i++)
			for (int j = i+1;j<pocet;j++) 
				if (x[i] == x[j] && y[i] == y[j]) {
					std::cout << provedeno;
					goto Konec;
				}
		provedeno++;
	}	
	std::cout << -1;
	Konec:
	delete[] x, y;
}

