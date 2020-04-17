#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> distances(std::vector<std::vector<int>> const& graph, int start) {

	int const V = graph.size();
	std::vector<int> distances(V, -1);
	distances[start] = 0;

	std::queue<int> queue;
	queue.push(start);

	while (!queue.empty()) {
		int const vertex = queue.front();
		queue.pop();

		for (int nei : graph[vertex]) 
			if (distances[nei] == -1) {
				distances[nei] = distances[vertex] + 1;
				queue.push(nei);
			}
	}
	return distances;
}

int solve() {

	int V;
	std::cin >> V;
	std::vector<std::vector<int>> cables(V);

	for (int i = 1; i < V; ++i) {
		int a, b;
		std::cin >> a >> b;
		cables[a].push_back(b);
		cables[b].push_back(a);
	}

	std::vector<int> dist = distances(cables, 0);
	int most_distatnt = 0;
	for (int i = 1; i < V; ++i)
		if (dist[i] > dist[most_distatnt])
			most_distatnt = i;

	dist = distances(cables, most_distatnt);
	int max = 0;
	for (int d : dist)
		if (d > max)
			max = d;


	return max % 2 == 0 ? max / 2 : max / 2 + 1;

}

int main(int, char**) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}