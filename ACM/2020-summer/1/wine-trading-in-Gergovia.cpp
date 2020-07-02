//https://www.spoj.com/problems/GERGOVIA/

#include <vector>
#include <iostream>
#include <set>

unsigned long long solve(int N) {

	std::set<int> sell, buy;
	std::vector<int> wine;
	wine.reserve(N);
	for (int i = 0; i < N; ++i) {
		int tmp;
		std::cin >> tmp;
		if (tmp >= 0) {
			buy.insert(i);
			wine.push_back(tmp);
		}
		else {
			sell.insert(i);
			wine.push_back(-tmp);
		}
	}

	unsigned long long moves = 0;

	auto buyer = buy.begin();
	for (auto seller = sell.begin(); seller != sell.end();) {
		int& sold = wine[*seller], &bought = wine[*buyer];

		if (sold <= bought) {
			moves += sold * std::abs(*seller - *buyer);
			bought -= sold;
			++seller;
			if (bought == 0)
				++buyer;
		}
		else { //sold > bought
			moves += bought * std::abs(*seller - *buyer);
			sold -= bought;
			++buyer;
		}
	}

	return moves;
}


int main() {
	std::ios_base::sync_with_stdio(false);

	for (int N; std::cin >> N, N;)
		std::cout << solve(N) << '\n';

}