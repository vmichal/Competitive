#include <iostream>
#include <vector>
#include <chrono>

int main() {
	std::vector<int> cisla;
	for (int i = 1; i <= 28123; i++) {
		int suma = 1;
		for (int j = 2; j < i; j++) 
			if (i % j == 0)
				suma += j;			
		if (suma > i)
			cisla.push_back(i);
	}
	auto nejvetsi = cisla.begin();
	int suma = 0;
	for (int i = 1; i <= 28123; i++) {									
		if (i >= *nejvetsi && nejvetsi != cisla.end()-1)
			nejvetsi++;
		bool add = true;
		for (auto zacatek = cisla.begin(), konec = nejvetsi; add && zacatek < konec;) {
			if (*zacatek + *konec == i)
				add = false;
			else if (*zacatek + *konec < i)
				zacatek++;
			else
				konec--;
		}
		if (add)
			suma += i;
	}
	std::cout << suma << std::endl;	 
	std::cin.get();
}