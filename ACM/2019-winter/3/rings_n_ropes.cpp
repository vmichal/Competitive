#include <iostream>
#include <vector>

int solve() {


	int N, E;
	std::cin >> N >> E;

	std::vector<std::vector<int>> distances(N, std::vector<int>(N, 1 << 24));
	std::vector<std::pair<int, int>> edges(E);

	for (int i = 0; i < N; ++i)
		distances[i][i] = 0;

	for (int i = 0; i < E; ++i) {
		int l, r;
		std::cin >> l >> r;
		edges[i] = { l, r };
		distances[l][r] = 1;
		distances[r][l] = 1;
	}

	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				int new_distance = distances[i][k] + distances[k][j];
				if (distances[i][j] > new_distance)
					distances[i][j] = new_distance;
			}

	auto const count = [&](int l, int r) {
		int sum = 0;
		for (auto const& edge : edges)
			if (distances[l][r] == distances[l][edge.first] + 1 + distances[edge.second][r]
				|| distances[l][r] == distances[l][edge.second] + 1 + distances[edge.first][r])
				sum++;
		return sum;
	};

	int max = 0;
	for (int i = 1; i < N; i++)
		for (int j = 0; j < i; j++) {
			int tmp = count(i, j);
			if (tmp > max)
				max = tmp;
		}
	return max;

}

int main(int, char**) {
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i)
		std::cout << "Case #" << i << ": " << solve() << '\n';
}