#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>

struct edge {
	long long src, dest, length;
};

std::vector<std::vector<edge>> input() {
	int V, E;
	std::cin >> V >> E;

	std::vector<std::vector<edge>> neighbours(V);

	for (int i = 0; i < E; ++i) {
		long long a, b, len;
		std::cin >> a >> b >> len;
		--a;
		--b;
		neighbours[a].push_back({ a,  b , len });
		neighbours[b].push_back({ b, a , len });
	}
	return neighbours;
}

#if 0
long long solve() {
	int price;
	std::cin >> price;

	std::vector<std::vector<edge>>   neighbours{ input() };
	std::vector<long long>           distances(neighbours.size(), std::numeric_limits<int>::max());
	std::vector<int>                 predecessors(neighbours.size(), -1);
	std::vector<bool>                visited(neighbours.size(), false);

	int const N = neighbours.size();

	auto vertex_with_lowest_value = [&]() -> int {
		int index_with_lowest_val = 0;

		for (; visited[index_with_lowest_val]; ++index_with_lowest_val);

		for (int i = index_with_lowest_val + 1; i < N; ++i)
			if (!visited[i] && distances[i] < distances[index_with_lowest_val])
				index_with_lowest_val = i;
		return index_with_lowest_val;
	};

	int const start = N / 2;
	distances[start] = 0;
	visited[start] = true;
	for (edge const& edge : neighbours[start]) {
		distances[edge.dest] = edge.length;
		predecessors[edge.dest] = start;
	}

	long long total_distance = 0;

	for (int visited_count = 1; visited_count < N; ++visited_count) {
		int const lowest = vertex_with_lowest_value();

		visited[lowest] = true;
		total_distance += distances[lowest] - distances[predecessors[lowest]];

		for (edge const& edge : neighbours[lowest])
			if (!visited[edge.dest]) {
				long long const possible_distance = distances[lowest] + edge.length;
				if (possible_distance < distances[edge.dest]) {
					distances[edge.dest] = possible_distance;
					predecessors[edge.dest] = lowest;
				}
			}
	}

	return total_distance * price;

}

#endif

long long solve() {
	//Solve using prim's algorithm to repeatedly find the current cheapest edge and mark it's destination as visited
	int price;
	std::cin >> price;

	std::vector<std::vector<edge>>   neighbours{ input() };
	std::vector<bool>                visited(neighbours.size(), false);

	int const N = neighbours.size();

	auto cheapest_edge = [&]() -> edge {

		edge const* best = nullptr;
		int best_length = std::numeric_limits<int>::max();

		for (int src = 0; src < N; ++src)
			if (visited[src])
				for (edge const& e : neighbours[src])
					if (!visited[e.dest] && e.length < best_length) {
						best = &e;
						best_length = e.length;
					}

		return *best;
	};

	visited[N / 2] = true;

	long long total_distance = 0;

	for (int visited_count = 1; visited_count < N; ++visited_count) {
		edge const e = cheapest_edge();

		visited[e.dest] = true;
		total_distance += e.length;

	}

	return total_distance * price;


}


int main(int, char**) {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}