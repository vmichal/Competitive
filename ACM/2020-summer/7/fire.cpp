//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=78&page=show_problem&problem=2671

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <deque>

constexpr int UNREACHABLE = 1000000000;

enum class square {
	wall, empty, finish, fire
};

struct coord {
	int y, x;
};

void solve() {
	int R, C;
	std::cin >> R >> C;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::vector<std::vector<square>> maze(R + 2, std::vector<square>(C + 2));
	std::deque<coord> joe;
	std::deque<coord> fire;


	{

		for (int x = 0; x < C + 2; ++x)
			maze[0][x] = square::finish;

		std::string line;
		for (int y = 1; y <= R; ++y) {
			maze[y][0] = square::finish;


			std::getline(std::cin, line);
			for (int x = 1; x <= C; ++x)
				switch (line[x - 1]) {
				case '#': maze[y][x] = square::wall; break;
				case '.': maze[y][x] = square::empty; break;
				case 'F': maze[y][x] = square::fire; fire.push_back({ y, x }); break;
				case 'J': maze[y][x] = square::empty; joe.push_back({ y, x }); break;
				}

			maze[y][C + 1] = square::finish;
		}

		for (int x = 0; x < C + 2; ++x)
			maze[R + 1][x] = square::finish;
	}

	std::vector<std::vector<int>> reach_time(R + 2, std::vector<int>(C + 2, UNREACHABLE));
	for (coord const c : fire)
		reach_time[c.y][c.x] = 0;

	while (!fire.empty()) {
		coord const current = fire.front();
		fire.pop_front();

		auto const available = [&](int y, int x) {
			return maze[y][x] == square::empty && reach_time[y][x] == UNREACHABLE;
		};

		if (available(current.y + 1, current.x)) {
			fire.push_back({ current.y + 1, current.x });
			reach_time[current.y + 1][current.x] = reach_time[current.y][current.x] + 1;
		}

		if (available(current.y - 1, current.x)) {
			fire.push_back({ current.y - 1, current.x });
			reach_time[current.y - 1][current.x] = reach_time[current.y][current.x] + 1;
		}

		if (available(current.y, current.x + 1)) {
			fire.push_back({ current.y, current.x + 1 });
			reach_time[current.y][current.x + 1] = reach_time[current.y][current.x] + 1;
		}

		if (available(current.y, current.x - 1)) {
			fire.push_back({ current.y, current.x - 1 });
			reach_time[current.y][current.x - 1] = reach_time[current.y][current.x] + 1;
		}
	}

	std::vector<std::vector<int>> enter_time(R + 2, std::vector<int>(C + 2, -1));
	enter_time[joe.front().y][joe.front().x] = 0;

	while (!joe.empty()) {
		coord const current = joe.front();
		int const next_time = enter_time[current.y][current.x] + 1;
		if (maze[current.y][current.x] == square::finish) {
			std::cout << (next_time - 1) << '\n';
			return;
		}

		joe.pop_front();


		auto const available = [&](int y, int x, int time) {
			return maze[y][x] != square::wall && reach_time[y][x] > time && enter_time[y][x] == -1;
		};

		if (available(current.y + 1, current.x, next_time)) {
			joe.push_back({ current.y + 1, current.x });
			enter_time[current.y + 1][current.x] = next_time;
		}

		if (available(current.y - 1, current.x, next_time)) {
			joe.push_back({ current.y - 1, current.x });
			enter_time[current.y - 1][current.x] = next_time;
		}

		if (available(current.y, current.x + 1, next_time)) {
			joe.push_back({ current.y, current.x + 1 });
			enter_time[current.y][current.x + 1] = next_time;
		}

		if (available(current.y, current.x - 1, next_time)) {
			joe.push_back({ current.y, current.x - 1 });
			enter_time[current.y][current.x - 1] = next_time;
		}

	}

	std::cout << "IMPOSSIBLE\n";
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i)
		solve();
}