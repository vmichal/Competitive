#include <iostream>
#include <algorithm>
#include <iterator>

int map[102][102];
int best[102][102];
int H, W;

#define max(i, j, k) (i > j && i > k ? i : j > k ? j : k)

int solve() {
	std::cin >> H >> W;
	for (int y = 1; y <= H; ++y) {
		for (int x = 1; x <= W; ++x)
			std::cin >> map[y][x];

		best[y][0] = best[y][W + 1] = 0;
	}

	for (int x = 1; x <= W; ++x)
		best[H][x] = map[H][x];

	for (int y = H - 1; y > 0; --y)
		for (int x = 1; x <= W; ++x)
			best[y][x] = map[y][x] + max(best[y + 1][x - 1], best[y + 1][x], best[y + 1][x + 1]);

	return *std::max_element(best[1] + 1, best[1] + 1 + W);
}


int main(int, char**) {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i)
		std::cout << solve() << std::endl;
}