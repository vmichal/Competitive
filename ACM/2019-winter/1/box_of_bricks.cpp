#include <iostream>
#include <vector>
#include <numeric>

int solve(int stack_count) {

	std::vector<int> stacks(stack_count);

	for (int& stack : stacks)
		std::cin >> stack;

	int const expected_height = std::accumulate(stacks.begin(), stacks.end(), 0) / stack_count;

	int moves = 0;
	for (int const stack : stacks)
		if (stack > expected_height)
			moves += stack - expected_height;

	return moves;
}

int main(int, char**) {

	for (int i = 1;; ++i) {
		int N;
		std::cin >> N;

		if (N == 0)
			break;

		std::cout << "Set #" << i << std::endl;
		std::cout << "The minimum number of moves is " << solve(N) << ".\n\n";
	}

}
