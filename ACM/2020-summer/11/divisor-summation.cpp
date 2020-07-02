//https://www.spoj.com/problems/DIVSUM/

#include <iostream>
#include <cmath>

int solve(int N) {

	int sum = 1;

	int sqrt = std::sqrt(N);

	for (int i = 2; i <= sqrt; ++i) {
		std::div_t const res = std::div(N, i);
		if (res.rem == 0)
			sum += i + res.quot;
	}

	if (sqrt * sqrt == N)
		sum -= sqrt;

	return sum;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	int N;
	std::cin >> N;
	for (int i = 0, tmp; i < N; ++i) {
		std::cin >> tmp;
		std::cout << solve(tmp) << '\n';

	}
}