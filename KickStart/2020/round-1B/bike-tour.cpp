//Google Kick Start 2020 Round B
//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6

#include <iostream>
#include <array>
#include <algorithm>
int solve() {

	int N;
	std::cin >> N;

	int count = 0;

	std::array<int, 3> heights = { {0} };
	std::cin >> heights[1] >> heights[2];

	for (int i = 2; i < N; ++i) {
		std::rotate(heights.begin(), heights.begin() + 1, heights.end());
		std::cin >> heights[2];
		if (heights[1] > heights[0] && heights[1] > heights[2])
			++count;
	}
	return count;
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i)
		std::cout << "Case #" << i << ": " << solve() << std::endl;
}
