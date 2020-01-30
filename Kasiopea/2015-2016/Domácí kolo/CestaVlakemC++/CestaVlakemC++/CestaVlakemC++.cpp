#include "stdafx.h"
#include <iostream>

void Solve() {
	int cil, maxPocetVlaku, pocetVlaku = 0, krok; 
	std::cin >> maxPocetVlaku;
	cil = maxPocetVlaku -1;
	while (1) {
		std::cin >> krok;		
		maxPocetVlaku--;
		cil -= krok;	
		pocetVlaku++;
		if (cil <= 0)
			break;
		for (int i = krok; i > 1; i--) {
			maxPocetVlaku--;
			std::cin >> krok;
		}
	}
	while (maxPocetVlaku-- > 0)
		std::cin >> krok;
	std::cout << pocetVlaku << "\n"; 
}

int main()
{
	int pocetTestu;
	std::cin >> pocetTestu;
	while (pocetTestu-- != 0) 
		Solve();			  
    return 0;
}

