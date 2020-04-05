#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

auto constexpr opening = [] {return '(';};
auto constexpr closing = [] {return ')';};

std::string solve() {

	std::string input;
	std::cin >> input;

	std::string result;
	result.reserve(100 * 20);
	auto output = std::back_inserter(result);

	int current_nesting = 0;

	for (char const c : input) {
		int const requested = c - '0';

		if (requested > current_nesting) 
			std::generate_n(output, requested - current_nesting, opening);
		else if (requested < current_nesting)
			std::generate_n(output, current_nesting - requested, closing);
		*output = c;
		current_nesting = requested;
	}
	std::generate_n(output, current_nesting, closing);

	return result;
}

int main(int, char**) {

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) 
		std::cout << "Case #"<< i << ": " << solve() << '\n';
}