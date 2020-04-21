//Codeforces Round 636
//Failing on one test case for unknown reason
//https://codeforces.com/contest/1343/problem/E

#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <array>
#include <numeric>


int solve() {
	int V, E, start, middle, finish;

	std::cin >> V >> E >> start >> middle >> finish;
	--start; --middle; --finish;

	std::vector<int> prizes(E);
	for (int& i : prizes)
		std::cin >> i;

	std::sort(prizes.begin(), prizes.end());

	std::vector<std::vector<int>> adjacency(V);

	for (int i = 0; i < E; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a; --b;
		adjacency[a].push_back(b);
		adjacency[b].push_back(a);
	}

	std::vector<int> preds(V, -1);
	preds[middle] = -2;


	std::queue<int> q;
	q.push(middle);

	while (!q.empty()) {
		int const current = q.front();
		q.pop();

		for (int const nei : adjacency[current])

			if (preds[nei] == -1) {
				preds[nei] = current;
				q.push(nei);
			}
	}

	std::vector<int> paths[2];
	std::array<int, 2> targets{ {start, finish} };

	for (int i = 0; i < 2; ++i) {
		int current = targets[i];
		while (current != middle) {
			paths[i].push_back(current);
			current = preds[current];
		}
		std::reverse(paths[i].begin(), paths[i].end());
	}

	auto const miss = std::mismatch(paths[0].begin(), paths[0].end(), paths[1].begin(), paths[1].end());

	int const shared = std::distance(paths[0].begin(), miss.first);
	int const divergent = std::distance(miss.first, paths[0].end()) + std::distance(miss.second, paths[1].end());

	return std::accumulate(prizes.begin(), prizes.begin() + shared, 0) * 2 + std::accumulate(prizes.begin() + shared, prizes.begin() + divergent+shared, 0);
}


int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}