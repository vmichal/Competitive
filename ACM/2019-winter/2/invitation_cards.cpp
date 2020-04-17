#include <iostream>
#include <vector>


struct edge {
	int dest, price;
};

int distances(std::vector<std::vector<edge>> graph) {

	int const V = graph.size();
	std::vector<short> visited(V, false);
	std::vector<int> dist(V, 2000000000);

	auto get_lowest = [&, init = 0]() mutable -> int {
		int pos = init;
		while (pos < V&& visited[pos]) ++pos;
		if (pos == V)
			return -1;
		init = pos;

		for (int i = pos + 1; i < V; ++i)
			if (!visited[i] && dist[i] < dist[pos])
				pos = i;
		return pos;
	};

	visited[0] = true;
	dist[0] = 0;

	for (edge const& e : graph[0])
		dist[e.dest] = e.price;

	int sum = 0;
	while (true) {
		int const vertex = get_lowest();
		if (vertex == -1)
			return sum;

		visited[vertex] = true;

		int const my_distance = dist[vertex];
		sum += my_distance;
		for (edge const& e : graph[vertex])
			if (!visited[e.dest]) {
				int const new_dist = my_distance + e.price;
				if (new_dist < dist[e.dest])
					dist[e.dest] = new_dist;
			}
	}

}

int solve() {

	int V, E;
	std::cin >> V >> E;

	std::vector<std::vector<edge>> departures(V);
	std::vector<std::vector<edge>> arrivals(V);

	for (int i = 0; i < E; ++i) {
		int a, b, p;
		std::cin >> a >> b >> p;
		--a; --b;
		departures[a].push_back({ b, p });
		arrivals[b].push_back({ a,p });
	}

	return distances(std::move(departures)) + distances(std::move(arrivals));
}

int main(int, char**) {
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << solve() << '\n';
}