//SPOJ problem RROOT - REAL ROOTS
//https://www.spoj.com/problems/RROO

#include <iostream>
#include <iomanip>
#include <cmath>

double solve(double S) {
	if (S <= 0)
		return 0;
	if (S < 1)
		return 0.5 + S / 12;
	return 0.5 + 2 / (3 * std::sqrt(S/2));
}

int main(int argc, char** argv) {

	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		double S;
		std::cin >> S;
		std::cout << std::setprecision(6) << solve(S) << std::endl;
	}

}