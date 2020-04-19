//11709 - Trust groups
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=155&page=show_problem&problem=2756

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
#include <unordered_map>
#include <cassert>

struct employee {
	int index;
	std::vector<int> trusts;
	std::vector<int> trusted_by;
};

std::vector<employee> read_input(int const N, int const E) {

	std::unordered_map<std::string, int> names;
	std::vector<employee> result(N);

	for (int i = 0; i < N; i++) {
		std::string line;
		std::getline(std::cin, line);
		names.emplace(std::move(line), i);

		result[i].index = i;
	}


	for (int i = 0; i < E; ++i) {
		std::string a, b;
		std::getline(std::cin, a);
		std::getline(std::cin, b);

		int const first = names[a], second = names[b];

		result[first].trusts.push_back(second);
		result[second].trusted_by.push_back(first);
	}

	return result;
}

std::vector<int> dfs(std::vector<employee> const& graph, std::vector<int> employee::* look_at, int const start, std::vector<bool>& visited) {

	std::vector<int> closing_times;
	closing_times.reserve(graph.size());
	std::stack<int> s;
	s.push(start);

	visited[start] = true;

	while (!s.empty()) {
		int const current = s.top();

		for (int const nei : graph[current].*look_at)
			if (!visited[nei]) {
				visited[nei] = true;
				s.push(nei);
				goto end;
			}


		s.pop();
		closing_times.push_back(current);
		end:;
	}
	return closing_times;
}

int solve(int const N, int const E) {

	std::vector<employee> graph = read_input(N, E);

	int const sinks = 0;

	std::vector<int> closing_times;
	closing_times.reserve(N);
	std::vector<bool> visited(N, false);

	for (;;) {
		auto const start = std::find(visited.begin(), visited.end(), false);
		if (start == visited.end())
			break;
		std::vector<int> const dfs_tree = dfs(graph, &employee::trusts, std::distance(visited.begin(), start), visited);
		for (int const found : dfs_tree)
			closing_times.push_back(found);
	}

	std::fill(visited.begin(), visited.end(), false);

	for (int components = 1;; ++components) {
		dfs(graph, &employee::trusted_by, closing_times.back(), visited);

		for (; !closing_times.empty() && visited[closing_times.back()]; closing_times.pop_back());
		if (closing_times.empty())
			return components + sinks;
	}
}

int main() {

	for (;;) {
		int N, E;
		std::cin >> N >> E;
		if (N == 0 && E == 0)
			break;
		std::cin.ignore(1);
		std::cout << solve(N, E) << std::endl;
	}
}