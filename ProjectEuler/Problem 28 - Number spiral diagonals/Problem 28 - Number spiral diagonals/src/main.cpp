#include <iostream>

#define MAX 1001

int main() {
	int strana = 3, soucet = 1, cislo = 1;
	

	while (strana <= MAX) {			  		
		soucet += cislo * 4 + 10 * strana - 10;
		cislo += 4 * strana - 4;
		strana += 2;
	}			   

	std::cout << cislo << " " << soucet << std::endl;
	std::cin.get();
}