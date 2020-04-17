#include <iostream>
#include <vector>
#include <algorithm>

int solve() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> actions;

	for (int i = 0; i < N; ++i) {
		int entry, exit;
		std::cin >> entry >> exit;
		actions.push_back({ entry, 1 });
		actions.push_back({ exit, -1 });
	}

	std::sort(actions.begin(), actions.end(),
		[](auto const& a, auto const& b) -> bool {
			return a.first < b.first;
		});

	int max = 0, current = 0;
	for (auto const& pair : actions) {
		current += pair.second;
		if (current > max)
			max = current;
	}

	return max;
}

int main(int, char**) {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cout << solve() << std::endl;
}