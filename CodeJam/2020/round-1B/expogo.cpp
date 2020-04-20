#include <string>
#include <numeric>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>


std::string solve() {

	int X, Y;
	std::cin >> X >> Y;

	bool const below = Y < 0;
	bool const left = X < 0;

	X = std::abs(X);
	Y = std::abs(Y);

	unsigned newX = X;
	unsigned newY = Y;

	for (unsigned shift = 0; ; ++shift) {
		unsigned const mask = 1 << shift;
		unsigned const next_mask = mask << 1;
		if ((newX & mask) == (newY & mask))
			return "IMPOSSIBLE";

		if (newY < next_mask && newX < next_mask)
			break;

		if ((newX & next_mask) == (newY & next_mask))
			if (newX & mask)
				newX += next_mask;
			else
				newY += next_mask;
	}

	unsigned const diffX = (newX - X) >> 1;
	unsigned const diffY = (newY - Y) >> 1;

	std::string solution;
	for (unsigned mask = 1; newY & mask || newX & mask; mask <<= 1)

		if (newY & mask)
			solution.push_back(diffY & mask ? 'S' : 'N');
		else
			solution.push_back(diffX & mask ? 'W' : 'E');


	if (solution.empty())
		return "IMPOSSIBLE";

	if (below)
		for (char& c : solution)
			if (c == 'N')
				c = 'S';
			else if (c == 'S')
				c = 'N';

	if (left)
		for (char& c : solution)
			if (c == 'E')
				c = 'W';
			else if (c == 'W')
				c = 'E';

	return solution;
}

int main() {
	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i)

		std::cout << "Case #" << i << ": " << solve() << '\n';
}