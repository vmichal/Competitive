#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> peers;
std::vector<bool> visited;
std::queue<int> queue;
int visited_count = 0;


int solve() {

	int V, E;
	std::cin >> V >> E;
	std::vector<std::vector<int>>(V).swap(peers);
	std::vector<bool>(V).swap(visited);
	for (int i = 0; i < E; ++i) {
		int a, b;
		std::cin >> a >> b;
		peers[a].push_back(b);
		peers[b].push_back(a);
	}

	if (E <= 2)
		return V - E;

	int components = 0;
	visited_count = 0;

	int last_checked_index = 0;
	while (visited_count != V) {
		++components;

		int next = last_checked_index;
		while (visited[next]) ++next;
		last_checked_index = next;
		visited[next] = true;
		visited_count++;
		queue.push(next);
		while (!queue.empty()) {
			int const current = queue.front();
			queue.pop();

			for (int peer : peers[current])
				if (!visited[peer]) {
					visited[peer] = true;
					++visited_count;
					queue.push(peer);
				}
		}
	}
	return components;
}


int main(int, char**) {
	std::ios_base::sync_with_stdio(false);

	int t;

	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}