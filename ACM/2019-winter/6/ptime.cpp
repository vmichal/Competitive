#if 0
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <cmath>

int power(int base, int exp) {
	int res = 1;
	for (int i = 0; i < exp; ++i)
		res *= base;
	return res;
}

int main(int, char**) {

	int N;
	std::cin >> N;

	std::vector<std::map<int, int>> factors(N + 1);


	int prime = 2;
	while (true) {
		while (prime <= N && !factors[prime].empty())
			++prime;
		if (prime > N)
			break;

		for (int value = prime; value <= N; value += prime)
			factors[value].emplace(prime, 1);

		for (int exp = 2; power(prime, exp) <= N; ++exp)
			for (int cached_power = power(prime, exp), value = cached_power; value <= N; value += cached_power)
				factors[value][prime]++;
	}

	std::map<int, int> exponents;
	for (int i = 2; i <= N; ++i)
		for (auto const& data : factors[i])
			exponents[data.first] += data.second;

	auto iterator = exponents.begin();

	std::cout << iterator->first << '^' << iterator->second;
	++iterator;
	for (auto const end = exponents.end(); iterator != end; ++iterator)
		std::cout << " * " << iterator->first << '^' << iterator->second;

	std::cout << '\n';

}

#endif