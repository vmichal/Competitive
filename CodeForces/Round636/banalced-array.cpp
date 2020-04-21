//Codeforces Round 636
//https://codeforces.com/contest/1343/problem/B


#include <iostream>

void solve() {

	int n;
	std::cin >> n;

	if (n % 4) {
		std::cout << "NO\n";
		return;
	}

	std::cout << "YES\n";

	int const count = n / 2;

	for (int i = 1; i <= count; ++i)
		std::cout << i * 2 << ' ';

	for (int i = 1; i < count; ++i)
		std::cout << i * 2 - 1 << ' ';
	std::cout << count * 3 - 1 << std::endl;
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}