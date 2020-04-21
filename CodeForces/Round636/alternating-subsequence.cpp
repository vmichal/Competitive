//Codeforces Round 636
//https://codeforces.com/contest/1343/problem/C


#include <iostream>
#include <utility>
#include <algorithm>
enum sign {
	plus, minus
};

constexpr sign signum(int x) {
	return x > 0 ? plus : minus;
}

long long solve() {

	int n;
	std::cin >> n;

	std::pair<int, long long> best[2];

	for (int i = 0; i < n; ++i) {
		int current;
		std::cin >> current;
		int const sign = signum(current);
		int const other = sign == plus ? minus : plus;

		int const length = 1 + best[other].first;
		long long const sum = current + best[other].second;

		if (length > best[sign].first || sum > best[sign].second)
			best[sign] = { length, sum };

	}

	if (best[plus].first != best[minus].first)
		return best[plus].first < best[minus].first ? best[minus].second : best[plus].second;
	return std::max(best[plus].second, best[minus].second);

}


int main() {

	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}