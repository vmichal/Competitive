//https://kasiopea.matfyz.cz/soutez/C/
#include <iostream>


unsigned long long int solve() {
	unsigned long long int pocetKoblih, pocetStran, velikostPanve;
	std::cin >> pocetKoblih >> pocetStran >> velikostPanve;
	if (pocetKoblih <= velikostPanve)
		return pocetStran;

	unsigned long long int pocetSmazeni = pocetKoblih * pocetStran;
	int long unsigned long time = pocetSmazeni / velikostPanve;
	if (time * velikostPanve < pocetSmazeni)
		++time;
	return time;
}

int main() {
	int T;
	for (std::cin >> T; T; T--)
		std::cout << solve() << std::endl;
}