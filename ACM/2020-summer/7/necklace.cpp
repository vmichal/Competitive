//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=38&page=show_problem&problem=995

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>

std::vector<int> find_circle(int from, std::array<std::vector<int>, 50 + 1>& colors) {

	std::vector<int> circle;
	assert(!colors[from].empty());
	circle.push_back(from);
		
	do {
		int const current = circle.back();
		std::vector<int>& edges = colors[current];

		int const count = std::count(edges.begin(), edges.end(), current);
		assert(count % 2 == 0);
		circle.insert(circle.end(), count / 2, current);
		edges.erase(std::remove(edges.begin(), edges.end(), current), edges.end());

		if (edges.empty()) {
			assert(circle.front() == circle.back());
			return circle;
		}

		int const target = edges.back();
		circle.push_back(target);

		edges.pop_back();
		colors[target].erase(std::find(colors[target].begin(), colors[target].end(), current));
	} while (circle.front() != circle.back());

	return circle;
}

void solve() {

	int N;
	std::cin >> N;

	std::array<std::vector<int>, 50 + 1> colors;
	std::array<bool, 50 + 1> reachable;

	for (int i = 0; i < N; ++i) {
		int left, right;
		std::cin >> left >> right;
		colors[left].push_back(right);
		colors[right].push_back(left);
	}

	for (auto& color : colors)
		if (color.size() % 2) {
			std::cout << "some beads may be lost\n";
			return;
		}

	int next_target = -1;
	for (int i = 1; i <= 50; ++i) 
		if (!colors[i].empty()) {
			next_target = i;
			break;
		}

	std::vector<int> solution = find_circle(next_target, colors);
	for (int vertex : solution)
		reachable[vertex] = true;

	for (;;) {
		next_target = -1;
		
		for (int i = 1; i <= 50; ++i)
			if (!colors[i].empty() && reachable[i]) {
				next_target = i;
				break;
			}
		if (next_target == -1)
			break;


		std::vector<int> circle = find_circle(next_target, colors);
		for (int vertex : circle)
			reachable[vertex] = true;


		assert(circle.front() == circle.back());
		auto const ptr = std::find(solution.begin(), solution.end(), circle.front());
		solution.insert(ptr, circle.begin() , circle.end() - 1);
	}

	std::cout << solution.front();

	for (int i = 1; i < solution.size() - 1; ++i)
		std::cout << ' ' << solution[i] << '\n' << solution[i];
	std::cout << ' ' << solution.back() << '\n';

}

int main() {
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << std::endl;
		solve();
		std::cout << std::endl;
	}
}