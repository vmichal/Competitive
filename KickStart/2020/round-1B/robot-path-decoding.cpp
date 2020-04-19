//Google Kick Start 2020 Round B
//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83dc

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

long long constexpr SIZE = 1e9;

struct coord {
	unsigned long long x, y;
};


constexpr coord& operator +=(coord& left, coord right) {
	left.x = (left.x + right.x) % SIZE;
	left.y = (left.y + right.y) % SIZE;

	return left;
}

constexpr coord operator*(coord a, int times) {
	a.x = (a.x * times) % SIZE;
	a.y = (a.y * times) % SIZE;

	return a;
}

constexpr coord from_direction(char c) {
	switch (c) {
	case 'W':
		return { SIZE - 1,0 };
	case 'E':
		return { 1,0 };
	case 'N':
		return { 0, SIZE - 1 };
	case 'S':
		return { 0,1 };
	default:
		assert(false);
	}
}

coord compute_subprogram(std::string::const_iterator& iter, std::string::const_iterator const end) {
	coord shift = { 0,0 };

	for (; iter != end && *iter != ')'; ++iter)
		if (isdigit(*iter)) {
			int const count = *iter - '0';
			iter += 2;
			shift += compute_subprogram(iter, end) * count;
		}
		else
			shift += from_direction(*iter);
	return shift;
}

coord solve() {

	std::string program;
	std::getline(std::cin, program);

	auto iter = program.cbegin();
	coord coord = compute_subprogram(iter, program.end());

	assert(iter == program.cend());

	if (coord.x < 0)
		coord.x += SIZE;
	if (coord.y < 0)
		coord.y += SIZE;

	++coord.x;
	++coord.y;
	return coord;
}


int main() {
	int T;
	std::cin >> T;
	std::cin.ignore(1);

	for (int i = 1; i <= T; ++i) {
		auto const result = solve();
		std::cout << "Case #" << i << ": " << result.x << ' ' << result.y << std::endl;
	}
}