#include <iostream>
#include <string>
#include <cmath>

int find_min_base(std::string const& num) {
	int radix = 2;

	for (char const c : num)
		if (isdigit(c)) {
			if (radix <= c-'0')
				radix = c -'0'+ 1;
		}
		else if (radix <= c - 'A' + 10)
			radix = c - 'A' + 10+1;
	return radix;
}

int value_of(std::string const& str, int base) {
	int value = 0;
	for (char c : str) {
		value = value*base + c-'0';
	}
	return value;
}

int main(int, char**) {

	std::string line;
	while (std::cin >> line && line.compare("0") != 0) {

		for (int base = find_min_base(line); base < 100; ++base) {
			int const value = value_of(line, base);
			int const root = std::sqrt(value);
			if (root * root == value) {
				std::cout << base << '\n';
				break;
			}
		}
	}
}