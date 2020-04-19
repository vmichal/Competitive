//Google Kick Start 2020 Round B
//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d8565

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

struct coord {
	int row, col;
};

constexpr bool operator==(coord a, coord b) {
	return a.col == b.col && a.row == b.row;
}

constexpr coord operator-(coord a, coord b) {
	a.col -= b.col;
	a.row -= b.row;
	return a;
}
constexpr coord operator+(coord a, coord b) {
	a.row += b.row;
	a.col += b.col;
	return a;
}

double solve() {
	coord size, top_left_tmp, bot_right_tmp;
	std::cin >> size.col >> size.row >> top_left_tmp.col >> top_left_tmp.row >> bot_right_tmp.col >> bot_right_tmp.row;


	//If either start or finish are missing, there is no way to reach the end successfully
	if (top_left_tmp == coord{ 1, 1 } || bot_right_tmp == size)
		return 0.0;


	coord const top_left = top_left_tmp - coord{ 1,1 };
	coord const bot_right = bot_right_tmp - coord{ 1,1 };
	coord const hole_size = bot_right - top_left + coord{ 1,1 };
	if (hole_size.row == size.row || hole_size.col == size.col)
		return 0.0; //There is a hole across a whole line -> no chance to jump over

	//special case of hole with height 1 snuggling the top wall -> simple math
	if (top_left.row == 0 && hole_size.row == 1)
		return 1.0 - std::pow(2.0, -top_left.col);

	//special case of hole with width one shuggling the left wall -> simple math again
	if (top_left.col == 0 && hole_size.col == 1)
		return 1.0 - std::pow(2.0, -top_left.row);
	//We will calculate the probability using dynamic programming on the rectangle above the hole.
	//It's bottom layer will be the below filled vector representing the topmost row, which is spanned by the hole


	std::vector<double> bottom_layer(bot_right.col + 1, 0.0);

	if (top_left.col > 0) { //If there is a gap between the left wall and hole
		auto const left_hole_begin = bottom_layer.begin() + top_left.col;

		if (bot_right.row == size.row - 1) //there is no way underneath, so fill bottom_layer with zeros
			;

		else { //there is a way under the hole
			std::vector<double> prev(top_left.col, 1.0);
			std::vector<double> current(top_left.col);

			for (int row = bot_right.row; row >= top_left.row; --row) {
				current.back() = (0.0 + prev.back()) / 2.0;
				for (int col = top_left.col - 2; col >= 0; --col)
					current[col] = (current[col + 1] + prev[col]) / 2.0;
				std::swap(current, prev);
			}
			std::copy(prev.begin(), prev.end(), bottom_layer.begin());
		}
	}

	if (top_left.row == 0) //If our hole actually snuggles the top wall, then bottom_layer now spans even the starting point. 
		return bottom_layer.front(); //Thus we can return straight away

	//Otherwise we are about to perform dynamic programming again. All vector sizes are now nonzero, guaranteed
	std::vector<double> current(top_left.row);
	//there is no path around it, so fill with zeros VS it ispossible to circumvent the hole
	std::vector<double> prev(top_left.row, bot_right.col == size.col - 1 ? 0.0 : 1.0);

	for (int col = bot_right.col; col >= 0; --col) {

		current.back() = (bottom_layer[col] + prev.back()) / 2.0;
		for (int row = top_left.row - 2; row >= 0; --row)
			current[row] = (current[row + 1] + prev[row]) / 2.0;
		std::swap(current, prev);
	}

	return prev.front();
}

int main() {
	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i)
		std::cout << "Case #" << i << ": " << std::setprecision(9) << solve() << std::endl;
}