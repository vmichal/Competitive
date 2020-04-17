#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <map>

constexpr char SPACE = '.';
int cols, rows;

int address(int y, int x) { return y * cols + x; }
std::pair<int, int> coord(int add) { return { add / cols, add % cols }; }

std::map<int,int> distances(std::map<int, std::vector<int>> const& graph, int start) {

	std::deque<int> waiting;
	std::map<int, int> distances;
	for (auto pair : graph)
		distances[pair.first] = -1;
	distances[start] = 0;
	for (auto nei : graph.at(start)) {
		waiting.push_back(nei);
		distances[nei] = 1;
	}

	while (true) {
		int vertex = waiting.back();
		waiting.pop_back();

		for (int nei : graph.at(vertex))
			if (distances[nei] == -1) {
				distances[nei] = distances[vertex] + 1;
				waiting.push_back(nei);
			}
		if (waiting.empty())
			return distances;
	}
}

std::map<int, std::vector<int>> read_graph(int const rows, int const cols) {

	std::vector<std::string> matrix(rows);

	for (int i = 0; i < rows; ++i) 
		std::getline(std::cin, matrix[i]);


	std::map<int, std::vector<int>> neighbours;
	for (int y = 0; y < rows - 1; ++y)
		for (int x = 0; x < cols - 1; ++x)
			if (matrix[y][x] == SPACE) {
				neighbours[address(y, x)];

				if (matrix[y + 1][x] == SPACE) {
					neighbours[address(y, x)].push_back(address(y + 1, x));
					neighbours[address(y + 1, x)].push_back(address(y, x));
				}
				if (matrix[y][x + 1] == SPACE) {
					neighbours[address(y, x)].push_back(address(y, x + 1));
					neighbours[address(y, x + 1)].push_back(address(y, x));
				}
			}
	return neighbours;
}

int solve() {

	std::cin >> cols >> rows;
	std::cin.ignore(10, '\n');

	std::map<int, std::vector<int>> graph = read_graph(rows, cols);
	int const V = graph.size();

	if (V == 1)
		return 0;

	std::map<int, int> dist = distances(graph, graph.begin()->first);

	int leaf = dist.begin()->first;
	for (auto pair : dist)
		if (pair.second > dist[leaf])
			leaf = pair.first;

	dist = distances(graph, leaf);
	int max = 0;
	for (std::pair<int, int> p : dist)
		if (p.second > max)
			max = p.second;
	return max;
}



int main(int, char**) {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << "Maximum rope length is " << solve() << ".\n";
}