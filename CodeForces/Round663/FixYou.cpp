#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int solve() {
	int rows, cols;
	std::cin >> rows >> cols;
	std::cin.ignore(10, '\n');
	std::vector<std::string> grid(rows);

	for (std::string & line : grid)
		std::getline(std::cin, line);

	int result = 0;
	for (int y = 0, end = rows -1; y < end; ++y)
		result += grid[y][cols-1] == 'R';

	auto const& last = grid.back();
	return result + std::count(last.begin(), last.end(), 'D');
}

int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i) 
		std::cout << solve() <<'\n';
}