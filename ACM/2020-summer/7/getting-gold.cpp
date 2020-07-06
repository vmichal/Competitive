//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=373&page=show_problem&problem=2597

#include <iostream>
#include <vector>
#include <string>

struct coord {
	int y, x;
};

coord operator+(coord a, coord b) {
	return coord{ a.y + b.y, a.x + b.x };
}

int counting_dfs(std::vector<std::string>& board, std::vector<std::vector<bool>> const& trap_nearby, coord start) {

	int res = board[start.y][start.x] == 'G';
	board[start.y][start.x] = 'x';

	if (trap_nearby[start.y][start.x])
		return res;

	int const H = board.size(), W = board.front().size();
	int score = 0;

	for (coord const dispacement : {coord{ -1,0 }, coord{ 1,0 }, coord{ 0,1 }, coord{ 0,-1 }}) {

		coord const nei = start + dispacement;

		if (0 <= nei.y && nei.y < H && 0 <= nei.x && nei.x < W && board[nei.y][nei.x] != '#' && board[nei.y][nei.x] != 'x')
			res += counting_dfs(board, trap_nearby, nei);
	}

	return res;
}

int solve() {
	int W, H;
	if (!(std::cin >> W >> H))
		exit(0);
	std::cin.ignore(10, '\n');

	std::vector<std::string> board(H);
	std::vector<std::vector<bool>> trap_nearby(H, std::vector<bool>(W, false));

	for (std::string& line : board)
		std::getline(std::cin, line);

	for (int y = 0; y < H; ++y)
		for (int x = 0; x < W; ++x)
			if (board[y][x] == 'T')
				for (coord const dispacement : {coord{ -1,0 }, coord{ 1,0 }, coord{ 0,1 }, coord{ 0,-1 }}) {

					coord const nei = coord{ y,x } + dispacement;

					if (0 <= nei.y && nei.y < H && 0 <= nei.x && nei.x < W)
						trap_nearby[nei.y][nei.x] = true;
				}

	for (int y = 0; y < H; ++y)
		for (int x = 0; x < W; ++x)
			if (board[y][x] == 'P')
				return counting_dfs(board, trap_nearby, { y, x });
}


int main() {
	for (;;)
		std::cout << solve() << '\n';
}