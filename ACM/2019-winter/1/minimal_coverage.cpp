#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <algorithm>


std::vector<std::vector<int>> read_neighbours(int M) {

	std::vector<std::vector<int>> segments(M);
	while (true) {
		int l, r;
		std::cin >> l >> r;
		if (l == 0 && r == 0) {
			std::cin.ignore(10, '\n');
			return segments;
		}
		if (l < r && l >= 0 && r <= M)
			segments[l].push_back(r);
	}
}

/*We are given a list of edges without weight between node 0 and node M and we should find the shortest path.


				It's BFS time!*/

void solve() {
	int M;
	std::cin >> M;

	std::vector<std::vector<int>> neighbours = read_neighbours(M);

	std::vector<int> predecessors(M + 1, -1);
	std::queue<int> waiting;

	waiting.push(0);

	while (!waiting.empty()) {

		int const vertex = waiting.front();
		waiting.pop();
		for (int const nei : neighbours[vertex])
			if (predecessors[nei] == -1) {//we have not visited this one yet
				predecessors[nei] = vertex;
				if (nei == M)
					break;
				waiting.push(nei);
			}
	}

	if (predecessors[M] == -1)
		std::cout << 0 << '\n';
	else {
		std::vector<std::pair<int, int>> path;
		int vertex = M;
		while (vertex) {
			int const pred = predecessors[M];
			path.push_back({ pred, vertex });
			vertex = pred;
		}
		std::reverse(path.begin(), path.end());
		std::cout << path.size() << '\n';
		for (auto const pair : path)
			std::cout << pair.first << ' ' << pair.second << '\n';
	}

	std::cout << '\n';
}


int main(int, char**) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
}
