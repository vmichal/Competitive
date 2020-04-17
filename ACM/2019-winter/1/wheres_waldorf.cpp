#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

struct coord {
	int y, x;
};

std::vector<std::vector<coord>> letter_coordinates{ 256 }; //assume single byte characters

std::vector<std::string> read_grid() {
	int m, n;
	std::cin >> m >> n;
	std::cin.ignore(10, '\n');
	std::vector<std::string> grid(m);

	for (int y = 0; y < m; ++y) {
		std::getline(std::cin, grid[y]);
		std::transform(grid[y].begin(), grid[y].end(), grid[y].begin(), ::tolower);
		for (int x = 0; x < n; x++)
			letter_coordinates[grid[y][x]].push_back({ y, x });
	}

	return grid;
}


std::vector<std::string> read_words() {

	int k;
	std::cin >> k;
	std::cin.ignore(10, '\n');
	std::vector<std::string> words(k);

	for (int i = 0; i < k; i++) {
		std::getline(std::cin, words[i]);
		std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
	}
	return words;
}

void solve() {
	for (auto& vec : letter_coordinates)
		vec.clear();

	std::vector<std::string> grid = read_grid();
	std::vector<std::string> words = read_words();

	std::vector<coord> solutions;
	for (std::string const& word : words) {
		for (coord const& start : letter_coordinates[word.front()]) {
			assert(grid[start.y][start.x] == word.front());
			for (int dx = -1; dx <= 1; ++dx)
				for (int dy = -1; dy <= 1; ++dy) {
					int x = start.x;
					int y = start.y;
					int index = 0;
					for (; x >= 0 && y >= 0 && y < grid.size() && x < grid.front().size(); ++index, x += dx, y += dy) {

						if (grid[y][x] != word[index])
							break;
						if (index == word.size() - 1) {
							solutions.push_back(start);
							goto end;
						}
					}
				}
		}
end:;
}

	for (auto const s : solutions)
		std::cout << s.y + 1 << ' ' << s.x + 1 << '\n';



}


int main(int, char**) {
	int T;
	std::cin >> T;

	solve();
	for (int i = 1; i < T; i++) {
		std::cout << '\n';
		solve();
	}
}
