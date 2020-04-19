//11631 - Dark roads
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=159&page=show_problem&problem=2678
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>


struct edge {
	int start, end, length;
};

constexpr bool operator>(edge const& a, edge const& b) {
	return a.length > b.length;
}

int solve(int const V, int const E) {

	std::vector<std::vector<edge>> G(V);

	int before_reduction = 0;

	for (int i = 0; i < E; ++i) {
		int s, e, w;
		std::cin >> s >> e >> w;
		G[s].push_back(edge{ s, e, w });
		G[e].push_back(edge{ e, s, w });

		before_reduction += w;
	}

	std::vector<bool> visited(V, false);
	visited[0] = true;
	std::priority_queue<edge,std::vector<edge>, std::greater<edge>> q;

	for (edge const& e : G[0])
		q.push(e);

	std::vector<edge> tree;
	tree.reserve(V-1);

	for (int i = 1; i < V; ) {
		edge const next = q.top();
		q.pop();

		if (visited[next.end])
			continue;
		++i;
		tree.push_back(next);
		visited[next.end] = true;
		for (edge const& e : G[next.end])
			q.push(e);
	}

	int after_reduction = 0;
	for (edge const& e : tree)
		after_reduction += e.length;

	return before_reduction - after_reduction;

}

int main() {

	for (;;) {
		int V, E;
		std::cin >> V >> E;
		if (V == 0 && E == 0)
			break;
		std::cout << solve(V, E) << std::endl;
	}

}