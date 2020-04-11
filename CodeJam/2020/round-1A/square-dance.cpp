#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>

struct dancer {

	int skills;
	int left, right, up, down;
	bool dead;

	int y, x;
};

unsigned long long solve() {

	int R, C;
	std::cin >> R >> C;

	std::vector<std::vector<dancer>> dancers(R + 1, std::vector<dancer>(C + 1));
	std::vector<dancer*> pointers;
	pointers.reserve((R + 1) * (C + 1));
	for (int y = 1; y <= R; y++)
		for (int x = 1; x <= C; x++) {

			dancer& d = dancers[y][x];

			d.y = y;
			d.x = x;

			std::cin >> d.skills;
			d.left = x - 1;
			d.up = y - 1;
			d.down = y + 1;
			d.right = x + 1;

			pointers.push_back(&d);
		}

	for (int i = 1; i <= R; ++i) {
		dancers[i][C].right = 0;
		dancers[i][1].left = 0;
	}

	for (int i = 1; i <= C; ++i) {
		dancers[R][i].down = 0;
		dancers[1][i].up = 0;
	}


	unsigned long long interest_level = 0;

	while (true) {
		bool stop = true;

		for (dancer* const ptr : pointers) {
			interest_level += ptr->skills;

			int sum = 0;
			int count = 0;

			if (ptr->left) {
				sum += dancers[ptr->y][ptr->left].skills;
				count++;
			}

			if (ptr->right) {
				sum += dancers[ptr->y][ptr->right].skills;
				count++;
			}

			if (ptr->up) {
				sum += dancers[ptr->up][ptr->x].skills;
				count++;
			}

			if (ptr->down) {
				sum += dancers[ptr->down][ptr->x].skills;
				count++;
			}

			if (ptr->skills * count < sum) {
				ptr->dead = true;
				stop = false;
			}
		}

		if (stop) 
			break;

		auto const new_end = std::partition(pointers.begin(), pointers.end(), [](dancer const* d) -> bool { return !d->dead; });
		auto const end = pointers.end();
		//Between new_end and end there are the dead boys.

		for (auto iter = new_end; iter != end; ++iter) {
			dancer* const ptr = *iter;

			if (ptr->left)
				dancers[ptr->y][ptr->left].right = ptr->right;

			if (ptr->right)
				dancers[ptr->y][ptr->right].left = ptr->left;

			if (ptr->up)
				dancers[ptr->up][ptr->x].down = ptr->down;

			if (ptr->down)
				dancers[ptr->down][ptr->x].up = ptr->up;

		}


		pointers.erase(new_end, end);
	}

	return interest_level;
}


int main(int, char**) {

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i)
		std::cout << "Case #" << i << ": " << solve() << std::endl;

}