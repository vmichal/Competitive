#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <limits>
#include <queue>


#define MAX_NODES 256

int N, E, Q;
int bussyness[MAX_NODES];
std::vector<int> neighbours[MAX_NODES];
int queries[MAX_NODES];
int distances[MAX_NODES];


void read_input() {
	for (int i = 1; i <= N; ++i)
		std::cin >> bussyness[i];
	std::cin >> E;

	for (auto& vec : neighbours)
		vec.clear();
	for (int i = 0; i < E; ++i) {
		int src, dest;
		std::cin >> src >> dest;
		neighbours[src].push_back(dest);
	}
	std::cin >> Q;
	for (int i = 0; i < Q; ++i)
		std::cin >> queries[i];
}

void relax() {
	for (int source = 1; source <= N; ++source)
		for (int const dest : neighbours[source]) {
			int const distance = bussyness[dest] - bussyness[source];
			int const price = distance * distance * distance + distances[source];
			if (price < distances[dest])
				distances[dest] = price;
		}
}

void bellman_ford(int start) {


	distances[start] = 0;

	for (int i = 0; i < N; ++i)
		relax();

	int cache[MAX_NODES];
	std::memcpy(cache, distances, sizeof(distances));
	for (int i = 0; i < N; ++i)
		relax();
	for (int i = 1; i <= N; ++i)
		if (cache[i] > distances[i])
			distances[i] = 0;





}

void bfs(int start) {

	bool visited[MAX_NODES] = { 0 };

	std::queue<int> queue;
	queue.push(start);
	visited[start] = true;

	while (!queue.empty()) {
		int const vertex = queue.front();
		queue.pop();

		for (int const nei : neighbours[vertex])
			if (!visited[nei]) {
				visited[nei] = true;
				queue.push(nei);
			}
	}
	for (int i = 0; i <= N; ++i)
		if (!visited[i]) {
			distances[i] = 0;
			neighbours[i].clear();
		}
}

int main() {

	for (int set = 1; ; ++set) {
		std::cin >> N;
		if (!std::cin)
			break;
		read_input();

		for (int i = 1; i <= N; ++i)
			distances[i] = 1000000000;
		bfs(1);
		bellman_ford(1);

		std::cout << "Set #" << set << '\n';
		for (int q = 0; q < Q; ++q) {
			int val = distances[queries[q]];
			if (val < 3)
				std::cout << "?\n";
			else
				std::cout << val << '\n';
		}
	}
}