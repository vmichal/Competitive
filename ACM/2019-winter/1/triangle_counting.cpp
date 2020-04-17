#include <iostream>
#include <algorithm>


unsigned long long solve(long long N) {

	/*triangular inequality:
	1) a + b > c
	2) a + c > b
	3) c + b > a // in this algorithm b is always bigger than a so this check can be skipped

	from the (1) and (2) we know, that b + a > c > b

	All possible values of c fall within a closed interval with lower bound b+1 and upper bound min(b + a - 1, N)

	*/
	unsigned long long count = 0;

#if 0
	for (int a = 2; a < N - 2; ++a)
		for (int b = a + 1; b < N - 1; ++b)
			count += std::min(b + a - 1, N) - b;
#endif



	for (long long a = 2; a <= N - 2; ++a) {
		long long upper = N - a - 1;
		long long lower = N - a - std::min(a - 1, upper);
		if (lower != upper) {
			long long n = upper - lower + 1;
			count += n * lower + n * (n - 1) / 2;
		}
		else
			count += lower;
	}



	return count;
}

int main(int, char**) {
	long long N;
	while (true) {
		std::cin >> N;
		if (N < 3)
			break;
		std::cout << solve(N) << '\n';
	}
}
