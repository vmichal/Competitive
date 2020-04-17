#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cassert>

int width, height;
std::vector<char> matrix;

#define address(x,y) y*width + x

std::vector<int> neighbours(int self) {
	int y = self / width;
	int x = self % width;

	std::vector<int> neighbours;

	for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy)
			if (dx || dy) {
				int new_x = x + dx, new_y = y + dy;
				if (new_x >= 0 && new_x < width && new_y >= 0 && new_y < height)
					neighbours.push_back(address(new_x, new_y));
			}
	return neighbours;
}

std::string ALLIZWELL = "ALLIZZWELL";


std::set<int> visited;

bool search_from(int offset, int index) {

	if (index == ALLIZWELL.size() - 1)
		return true;

	visited.insert(offset);

	bool found = false;
	for (int const addr : neighbours(offset))
		if (!visited.count(addr) && matrix[addr] == ALLIZWELL[index + 1])
			if (search_from(addr, index + 1)) {
				found = true;
				break;
			}
	visited.erase(offset);
	return found;
}


bool solve() {

	std::cin >> height >> width;
	matrix.resize(height * width);

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x)
			std::cin >> matrix[address(x, y)];
		std::cin.ignore(10, '\n');
	}

	for (int offset = 0; offset < width * height; ++offset)
		if (matrix[offset] == 'A')
			if (search_from(offset, 0))
				return true;
	return false;
}

int main(int, char**) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		std::cout << (solve() ? "YES\n" : "NO\n");

}