// Příliš bílý displej.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

struct tvar {
	int x1, y1, x2, y2;
	tvar(int _x1, int _y1, int _x2, int _y2) {
		x1 = _x1;
		x2 = _x2;
		y1 = _y1;
		y2 = _y2;
	}

	int obsah() {
		return (x2 - x1) * (y2 - y1);
	}
};

void Zarad(std::vector<tvar> tvary, tvar tvar) {
	for (int i = 0; i < tvary.size(); i++) {
		if (tvary)
	}	
}

int main() {
	int sirka, vyska, pocetPozadavku;
	std::cin >> sirka >> vyska >> pocetPozadavku;
	std::vector<tvar> tvary;
	while (pocetPozadavku-- > 0) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		Zarad(tvary, tvar(x1, y1, x2, y2));
	}	 
	int obsah = 0;
	for (int i = 0; i < tvary.size(); i++)
		obsah += tvary[i].obsah();
    return 0;
}

