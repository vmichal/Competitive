//Google Kick Start 2020 Round B
//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

long long solve() {
	int  N;
	unsigned long long D;
	std::cin >> N >> D;

	std::vector<unsigned long long> buses(N);

	for (unsigned long long& bus : buses)
		std::cin >> bus;

	for (auto iter = buses.crbegin(), end = buses.crend(); iter != end; ++iter)
		D -= D % *iter;

	return D;
}


int main() {
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i)
		std::cout << "Case #" << i << ": " << solve() << std::endl;
}