#include <iostream>
#include <vector>
#include <tuple>
#include <set>


constexpr int maxN = 100;

int matrix[maxN + 1][maxN + 1];


std::tuple<int, int, int> solve() {

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) 
			std::cin >> matrix[i][j];

	int sum  = 0;
	for (int i = 0;i < N; ++i)
		sum += matrix[i][i];

	int rows = 0;
	for (int row = 0; row < N; ++row) {
		std::set<int> seen;
		seen.insert(matrix[row][0]);
		for (int col = 1;col < N; ++col)
			if (seen.count(matrix[row][col])) {
				rows++;
				break;
			}
			else
				seen.insert(matrix[row][col]);
	}

	int cols = 0;
	for (int col = 0; col < N; ++col) {
		std::set<int> seen;
		seen.insert(matrix[0][col]);
		for (int row = 1; row < N; ++row)
			if (seen.count(matrix[row][col])) {
				cols++;
				break;
			}
			else
				seen.insert(matrix[row][col]);
	}

	return {sum, rows, cols};
}

int main(int, char**) {
	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {

		auto const result = solve();

		std::cout << "Case #" << i << ": " << std::get<0>(result) << ' ' << std::get<1>(result) << ' ' << std::get<2>(result) << '\n';
	}

}