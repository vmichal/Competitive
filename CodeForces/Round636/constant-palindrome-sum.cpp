//Codeforces Round 636
//https://codeforces.com/contest/1343/problem/D


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

int solve() {

	int n, k;
	std::cin >> n >> k;

	std::vector<int> left(n / 2), right(n / 2);
	std::vector<int> all(n);

	for (int& i : left)
		std::cin >> i;
	for (auto iter = right.rbegin(), end = right.rend(); iter != end; ++iter)
		std::cin >> *iter;

	std::copy(left.begin(), left.end(), all.begin());
	std::copy(right.rbegin(), right.rend(), all.rbegin());

	std::vector<int> sums(n / 2);
	std::transform(left.begin(), left.end(), right.begin(), sums.begin(), std::plus<int>{});

	auto const [min, max] = std::minmax_element(all.begin(), all.end());

	auto [min_sum, max_sum] = std::minmax_element(sums.begin(), sums.end());

	int const allowable_min = *min + 1;
	int const allowable_max = *min + k;

	return -1;
}


int main() {

	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}