
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=152&page=show_problem&problem=196

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>
#include <array>

struct coord {
	int row, col;
};

constexpr coord operator+(coord a, coord b) {
	return { a.row + b.row, a.col + b.col };
}

constexpr std::array<coord, 6> neighbours = { {
	{-1,-1},
	{-1,0},
	{0,-1},
	{0,1},
	{1,0},
	{1,1}
	} };

bool in_bounds(coord const c, int N) {
	return c.col >= 0 && c.col < N && c.row >= 0 && c.row < N;
}

char solve(int const N) {

	std::vector<std::string> map(N);

	for (std::string& line : map)
		std::cin >> line;

	std::vector<std::vector<bool>> reached(N, std::vector<bool>(N, false));

	std::queue<coord> q;

	for (int col = 0; col < N; ++col)
		if (map[0][col] == 'b') {
			q.push({ 0,col });
			reached[0][col] = true;
		}

	if (std::count(map.back().begin(), map.back().end(), 'b') == 0 || q.empty())
		return 'W'; //If either first or last line are fully white, then white must have won


	while (!q.empty()) {
		coord const current = q.front();
		q.pop();

		for (coord const nei : neighbours) {
			coord const res =  current + nei;
			if (in_bounds(res, N) && map[res.row][res.col] == 'b' && !reached[res.row][res.col]) {
				reached[res.row][res.col] = true;
				q.push(res);
				if (res.row == N -1)
					return 'B'; //We have reached the last line
			}
		}

	}

	return 'W'; //If we found no way, then white must have won
}


int main(int, char**) {

	for (int i = 1; ; ++i) {
		int N;
		std::cin >> N;
		if (N == 0)
			break;
		std::cout << i << ' ' << solve(N) << '\n';
	}
}