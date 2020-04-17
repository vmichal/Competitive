#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <set>

constexpr char SPACE = '.';
constexpr char WALL = '#';

std::vector<std::pair<int, int>> find_exits(std::vector<std::string> const& maze) {

	int const rows = maze.size(),
		cols = maze.front().size();



	std::vector<std::pair<int, int>> exits;

	if (maze[0][0] == SPACE)
		exits.push_back({ 0,0 });

	if (rows > 1 && maze[rows - 1][0] == SPACE)
		exits.push_back({ rows - 1,0 });


	if (cols > 1 && maze[0][cols - 1] == SPACE)
		exits.push_back({ 0,cols - 1 });

	if (rows > 1 && cols>1 && maze[rows - 1][cols - 1] == SPACE)
		exits.push_back({ rows - 1,cols - 1 });

	for (int x = 1; x < cols - 1; ++x)
		if (maze[0][x] == SPACE)
			exits.push_back({ 0,x });
	if (rows != 1)
		for (int x = 1; x < cols - 1; ++x)
			if (maze[rows - 1][x] == SPACE)
				exits.push_back({ rows - 1,x });

	for (int y = 1; y < rows - 1; ++y) {
		if (maze[y][0] == SPACE)
			exits.push_back({ y,0 });
		if (cols != 1 && maze[y][cols - 1] == SPACE)
			exits.push_back({ y,cols - 1 });
	}

	return exits;
}

bool exists_path(std::vector<std::string> const& maze, std::pair<int, int> start, std::pair<int, int> end) {

	auto const neighbours = [&](std::pair<int, int> cell) -> std::vector<std::pair<int, int>> {
		int const rows = maze.size(),
			cols = maze.front().size();

		std::vector<std::pair<int, int>> neighbours;

		if (cell.first > 0)
			neighbours.push_back({ cell.first - 1, cell.second });
		if (cell.second > 0)
			neighbours.push_back({ cell.first , cell.second - 1 });

		if (cell.first < rows - 1)
			neighbours.push_back({ cell.first + 1, cell.second });

		if (cell.second < cols - 1)
			neighbours.push_back({ cell.first , cell.second + 1 });

		return neighbours;
	};

	std::set<std::pair<int, int>> visited;
	visited.insert(start);
	std::stack<std::pair<int, int>> waiting;
	for (auto pair : neighbours(start))
		if (maze[pair.first][pair.second] != WALL) {
			waiting.push(pair);
			visited.insert(pair);
		}

	while (!visited.count(end) && !waiting.empty()) {
		auto next = waiting.top();
		waiting.pop();


		for (auto nei : neighbours(next))
			if (!visited.count(nei) && maze[nei.first][nei.second] != WALL) {
				visited.insert(nei);
				waiting.push(nei);
			}
	}
	return visited.count(end);
}

bool solve() {

	int rows, cols;
	std::cin >> rows >> cols;
	std::cin.ignore(10, '\n');

	std::vector<std::string> maze(rows);

	for (int y = 0; y < rows; ++y)
		std::getline(std::cin, maze[y]);

	auto exits = find_exits(maze);
	if (exits.size() != 2)
		return false;


	return exists_path(maze, exits[0], exits[1]);
}

int main(int, char**) {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << (solve() ? "valid" : "invalid") << std::endl;
}