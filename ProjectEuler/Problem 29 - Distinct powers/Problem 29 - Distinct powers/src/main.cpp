#include <iostream>
#include "BigInteger.h"

#define MAX 100
   
int main() {
	std::vector<BigInteger*> cisla;
	cisla.reserve(10'000);
	for (int i = 2; i <= MAX; i++) {
		BigInteger *a = new BigInteger(i*i);
		for (int j = 2; j < MAX; j++) {
			cisla.push_back(a);
			a = new BigInteger(*a*i);
		}
		cisla.push_back(a);
	}
	std::vector<BigInteger*>::iterator konec = --cisla.end(), nejvetsi, iterator;
	while (konec != cisla.begin()) {		 				
		for (iterator = nejvetsi = cisla.begin(); iterator <= konec; iterator++) 
			if (**iterator > **nejvetsi) 
				nejvetsi = iterator;
		if (**konec != **nejvetsi) {
			BigInteger *tmp = *konec;
			*konec = *nejvetsi;
			*nejvetsi = tmp;
		}
		konec--;
	}
	uint32_t count = 0;
	for (auto iterator = cisla.begin(); iterator != cisla.end(); iterator++) {
		count++;																								 
		while (iterator < cisla.end() - 1 && **(iterator + 1) == **iterator)
			iterator++;
	}
	for (BigInteger* ref : cisla) 
		delete ref;				  
	std::cout << count << std::endl;
	std::cin.get();
}