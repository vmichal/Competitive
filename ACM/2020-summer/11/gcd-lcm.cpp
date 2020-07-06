//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=189&page=show_problem&problem=2383

#include <set>
#include <iostream>
#include <cmath>
#include <algorithm>

std::multiset<int> prime_decomposition(int x) {
	if (x == 1)
		return {};
	std::multiset<int> result;

	int const sqrt = std::sqrt(x);
	for (int i = 2; i < x; )
		if (x % i == 0) {
			x /= i;
			result.insert(i);
		}
		else 
			++i;
	result.insert(x);

	return result;
}

void solve() {

	int G, L;
	std::cin >> G >> L;

	std::multiset<int> g = prime_decomposition(G), l = prime_decomposition(L);

	if (!std::includes(l.begin(), l.end(), g.begin(), g.end()))
		std::cout << "-1\n";
	else {
		std::cout << G << ' ' << L << '\n';
	}


}

int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
		solve();
}
