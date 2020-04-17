#include <iostream>
#include <array>

int solve(int N) {

	if (N == 0)
		return 10;
	if (N == 1)
		return 1;

	int result = 0;

	int p = 1;
	auto power = [&p]() { int result = p; p *= 10; return result; };

	for (int i = 9; i >= 2; --i)
		for (; N % i == 0; N /= i) 
			result += i * power();

	if (N > 1)
		return -1;

	return result;
}

int main(int, char**) {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i) {
		int N;
		std::cin >> N;
		std::cout << solve(N) << std::endl;
	}
}

