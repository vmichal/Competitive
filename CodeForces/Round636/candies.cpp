//Codeforces Round 636
//https://codeforces.com/contest/1343/problem/A

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <iterator>

int solve() {

	int n;

	std::cin >> n;

	for (unsigned mask = 0xffffffff; mask; mask >>= 1)
		if (n % mask == 0)
			return n / mask;
}

int main() {

	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;

}