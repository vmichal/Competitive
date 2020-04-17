#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

struct edge {
	int dest, value;
};

double solve(int V) {
	int E;
	std::cin >> E;

	std::vector<std::vector<edge>> streets(V);

	for (int i = 0; i < E; ++i) {
		int a, b, p;
		std::cin >> a >> b >> p;
		--a;
		--b;
		streets[a].push_back({ b,p });
		streets[b].push_back({ a,p });
	}

	std::vector<double> probability(V, 0.0);
	std::vector<bool> visited(V, false);
	probability[0] = 1.0;
	visited[0] = true;
	for (edge e : streets[0])
		probability[e.dest] = e.value / 100.0;

	auto get_highest = [&]() -> int {
		int highest = 0;
		for (; highest < visited.size() && visited[highest]; ++highest);
		if (highest == visited.size())
			return -1;

		for (int i = highest + 1; i < visited.size(); ++i)
			if (!visited[i] && probability[i] > probability[highest])
				highest = i;
		return highest;
	};


	while (!visited[V - 1]) {
		int const vertex = get_highest();
		if (vertex == V - 1)
			return probability[vertex] * 100;

		visited[vertex] = true;
		for (edge e : streets[vertex])
			if (!visited[e.dest]) {
				double possible = probability[vertex] * e.value / 100.0;
				if (possible > probability[e.dest])
					probability[e.dest] = possible;
			}
	}
}

int main(int, char**) {
	for (;;) {

		int V;
		std::cin >> V;
		if (V == 0)
			break;
		std::cout << std::fixed << std::setprecision(6) << solve(V) << " percent\n";
	}
}