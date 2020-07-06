//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2620

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

enum {
	N = '0', NE, E, SE, S, SW, W, NW
};

std::vector<std::string> ocean;
std::vector<std::vector<int>> visit_time;
struct coord {
	int y, x;
};
auto const lambda = [](coord c) ->int& {return visit_time[c.y][c.x]; };
auto const exists = [](coord c) -> bool {return 0 <= c.y && c.y < ocean.size() && 0 <= c.x && c.x < ocean.front().size(); };
coord operator+(coord a, coord b) {
	return { a.y + b.y, a.x + b.x };
}

coord displacement(char dir) {
	switch (dir) {
	case N: return { -1,0 };
	case NE: return { -1,1 };
	case E: return { 0,1 };
	case SE: return { 1,1 };
	case S: return { 1,0 };
	case SW: return { 1,-1 };
	case W: return { 0,-1 };
	case NW: return { -1,-1 };
	}
}

int solve(coord start, coord dest) {
	for (auto& line : visit_time)
		std::fill(line.begin(), line.end(), -1);

	std::vector<coord> layer;
	std::vector<coord> next;
	layer.reserve(1000 * 1000);
	next.reserve(1000 * 1000);

	lambda(start) = 0;
	next.push_back(start);

	for (; lambda(dest) == -1;) {
		next.swap(layer);

		for (int i = 0; i < layer.size(); ++i) {
			coord const current = layer[i];
			coord const cheap = current + displacement(ocean[current.y][current.x]);


			if (exists(cheap) && lambda(cheap) == -1) {
				lambda(cheap) = lambda(current);
				layer.push_back(cheap);
			}

		}

		for (coord const current : layer)
			for (int dir : {N, NE, E, SE, S, SW, W, NW}) {
				coord const nei = current + displacement(dir);
				if (exists(nei) && lambda(nei) == -1) {
					lambda(nei) = lambda(current) + 1;
					next.push_back(nei);
				}
			}
		layer.clear();

	}
	return lambda(dest);

}

int main() {

	int r, c;
	std::cin >> r >> c;
	std::cin.ignore(10, '\n');
	ocean.resize(r);
	visit_time.resize(r, std::vector<int>(c, -1));
	for (std::string& line : ocean)
		std::getline(std::cin, line);

	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		int rs, cs, rd, cd;
		std::cin >> rs >> cs >> rd >> cd;
		std::cout << solve({ rs - 1, cs - 1 }, { rd - 1, cd - 1 }) << '\n';
	}

}