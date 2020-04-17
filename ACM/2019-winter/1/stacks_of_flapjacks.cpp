#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

std::vector<int> convert(std::string const& str) {
	std::istringstream stream{ str };
	std::vector<int> result{ std::istream_iterator<int>{stream}, std::istream_iterator<int>{} };
	std::reverse(result.begin(), result.end());
	return result;
}

void flip(std::vector<int>& stack, int pos) {

	for (int i = pos, j = stack.size() - 1; i < j; ++i, --j)
		std::swap(stack[i], stack[j]);
}

void solve(std::vector<int> stack) {

	std::vector<int> sorted = stack;
	std::sort(sorted.begin(), sorted.end(), std::greater<int>{});

	for (int i = 0; i < stack.size(); ++i) {
		if (stack[i] == sorted[i])
			continue;
		int const index_highest_unsorted = std::find(stack.begin() + i, stack.end(), sorted[i]) - stack.begin();
		if (index_highest_unsorted != stack.size() - 1) {
			flip(stack, index_highest_unsorted);
			std::cout << index_highest_unsorted + 1 << ' ';
		}
		flip(stack, i);
		std::cout << i + 1 << ' ';
	}

	std::cout << "0\n";
}

int main(int, char**) {

	std::string line;
	while (std::getline(std::cin, line)) {
		std::cout << line << std::endl;
		solve(convert(line));
	}

}