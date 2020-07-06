//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=37&page=show_problem&problem=1008

#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <limits>

using value = std::array<unsigned, 4>;

int hash(value v) {
	return v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}

int solve() {
	value v;
	std::cin >> v[0] >> v[1] >> v[2] >> v[3];
	value const start = v;

	std::cin >> v[0] >> v[1] >> v[2] >> v[3];
	int const end = hash(v);

	int N;
	std::cin >> N;
	std::vector<int> prohibited(10010);
	for (int i = 0; i < N; ++i) {
		std::cin >> v[0] >> v[1] >> v[2] >> v[3];
		prohibited[hash(v)] = true;
	}
	if (prohibited[end])
		return -1;

	std::vector<bool> seen(10010);

	std::vector<value> layer, next;
	next.push_back(start);
	seen[hash(start)] = true;

	for (int steps = 0; !next.empty(); ++steps) {

		if (seen[end])
			return steps;

		next.swap(layer);

		for (value const& v : layer) {

			for (int i = 0; i < 4; ++i) {

				value u = v, d = v;

				if (++u[i] == 10)
					u[i] = 0;

				if (--d[i] == std::numeric_limits<unsigned>::max())
					d[i] = 9;

				int const hashu = hash(u), hashd = hash(d);

				if (!seen[hashd] && !prohibited[hashd]) {
					seen[hashd] = true;
					next.push_back(d);
				}

				if (!seen[hashu] && !prohibited[hashu]) {
					seen[hashu] = true;
					next.push_back(u);
				}
			}
		}
		layer.clear();
	}
	return -1;
}


int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i)
		std::cout << solve() << '\n';
}

