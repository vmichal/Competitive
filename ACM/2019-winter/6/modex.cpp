#if 0
#include <iostream>


unsigned long long exponentiation(int const base, int const exp, int const prime) {
	if (exp == 1)
		return base;

	unsigned long long  res = exponentiation(base, exp/2,prime) % prime;
	res = res * res;

	if (exp & 1) 
		res *= base;
	return res;
}


int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		int base, exp, prime;
		std::cin >> base >> exp >> prime;
		std::cout << exponentiation(base, exp, prime) % prime << '\n';
	}

}
#endif