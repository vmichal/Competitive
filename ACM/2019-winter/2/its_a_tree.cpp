#include <iostream>
#include <vector>
#include <set>
#include <queue>


bool solve() {
	int V, E;
	std::cin >> V >> E;

	if (E != V - 1)
		return false;

	std::vector<std::vector<int>> neighbours(V);

	for (int i = 0; i < E; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u;
		--v;
		neighbours[u].push_back(v);
		neighbours[v].push_back(u);
	}

	std::set<int> visited;
	std::queue<int> queue;
	std::vector<int> pred(V, -1);

	visited.insert(0);
	for (int const nei : neighbours[0]) {
		pred[nei] = 0;
		visited.insert(nei);
		queue.push(nei);
	}

	while (!queue.empty()) {
		int vertex = queue.front();
		queue.pop();

		for (int const nei : neighbours[vertex])
			if (nei != pred[vertex])
				if (visited.count(nei))
					return false;
				else {
					visited.insert(nei);
					queue.push(nei);
					pred[nei] = vertex;
				}
	}
	return visited.size() == V;
}

int main(int, char**) {
	std::cout << (solve() ? "YES" : "NO") << std::endl;


}