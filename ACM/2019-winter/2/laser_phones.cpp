#include <iostream>
#include <string>
#include <vector>
#include <queue>


int W, H, V;
int address(int y, int x) {
	return y * W + x;
}

enum class direction {
	none, left, right, up, down
};

std::vector<char> matrix;
std::vector<int> cows;

void read() {

	std::cin >> W >> H;
	W += 2; H += 2;
	V = W * H;

	matrix.resize(V);


	for (int i = 0; i < W; ++i)
		matrix[i] = '*';
	for (int y = 1; y < H - 1; ++y) {
		matrix[address(y, 0)] = '*';
		for (int x = 1; x < W - 1; ++x)
			std::cin >> matrix[address(y, x)];
		matrix[address(y, W - 1)] = '*';
		std::cin.ignore(10, '\n');
	}
	for (int x = 0; x < W; ++x)
		matrix[address(H - 1, x)] = '*';

	for (int y = 1; y < H - 1; ++y)
		for (int x = 1; x < W - 1; ++x)
			if (matrix[address(y, x)] == 'C') {
				cows.push_back(address(y, x));
				matrix[address(y, x)] = '.';
			}
}


int main(int, char**) {

	read();

	std::vector<int> dist(V, -1);
	std::vector<direction> directions(V, direction::none);
	std::queue<int> queue;



	auto uncover = [&](int point, direction dir) {

		int const dy = dir == direction::up ? -1 : dir == direction::down ? 1 : 0;
		int const dx = dir == direction::left ? -1 : dir == direction::right ? 1 : 0;

		int x = point % W + dx;
		int y = point / W + dy;

		int new_dist = dist[point] + 1;
		while (matrix[address(y, x)] != '*') {

			if (dist[address(y, x)] == -1) {
				dist[address(y, x)] = new_dist;
				directions[address(y, x)] = dir;
				queue.push(address(y, x));
			}
			x += dx;
			y += dy;
		}

	};

	uncover(cows.front(), direction::up);
	uncover(cows.front(), direction::down);
	uncover(cows.front(), direction::right);
	uncover(cows.front(), direction::left);
	dist[cows.front()] = 0;

	while (dist[cows.back()] == -1) {
		int const vertex = queue.front();
		queue.pop();

		if (directions[vertex] == direction::up || directions[vertex] == direction::down) {
			uncover(vertex, direction::left);
			uncover(vertex, direction::right);
		}

		if (directions[vertex] == direction::left || directions[vertex] == direction::right) {
			uncover(vertex, direction::down);
			uncover(vertex, direction::up);
		}
	}
	std::cout << dist[cows.back()] << std::endl;
}