#include <iostream>
#include <vector>
#include <queue>

bool solve(int nodes) {

	int edges;
	std::cin >> edges;

	std::vector<int> connect[200];

	for (int l = 0; l < edges; ++l) {
		int start, end;
		std::cin >> start >> end;
		connect[start].push_back(end);
		connect[end].push_back(start);
	}

	std::queue<int> queue;
	queue.push(0); //start the flood fill


	int color[200];
	for (int & c : color)
		c = 0;

	while (! queue.empty()) {

		int const current = queue.front();
		queue.pop();

		bool used[2] = {false, false};

		for (int vertex : connect[current]) {
			if (color[vertex] == 0)
				queue.push(vertex);
			else 
				used[color[vertex]-1] = true;
		}
		if (used[0] && used[1])
			return false;

		color[current] = used[0] ? 2 : 1;
	}

	return true;
}

int main() {

	for (;;) {
		int nodes;
		std::cin >> nodes;
		if (nodes == 0)
			break;

		std::cout << (solve(nodes) ? "BICOLORABLE." : "NOT BICOLORABLE.") << '\n';

	}


}