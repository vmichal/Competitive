#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

float hypot(int a, int b) {

	return std::sqrt(a*a + b*b);

}

float solve() {

	int satelites, outposts;
	std::cin >> satelites >> outposts;

	std::vector<std::pair<int, int>> coords(outposts);

	for (int i = 0; i < outposts; ++i) 
		std::cin >> coords[i].first >> coords[i].second;


	std::vector<std::vector<float>> distances(outposts, std::vector<float>(outposts));

	for (int i = 0; i < outposts; ++i)
		for (int j = i + 1;j < outposts; ++j)
			distances[i][j] = hypot(coords[i].first - coords[j].first, coords[i].second - coords[j].second);

	for (int s = 0; ; s += 2) {
		for (int i = 0;i < outposts; ++i)
			for (int j = 0; j < outposts; ++j)
				for (int k = 0; k < outposts; ++k) 
					if (distances[j][k] > distances[i][k] + distances[j][k]) 
						distances[j][k] = distances[i][k] + distances[j][k];

		float max_distance = 0.0f;
		int a = -1, b = -1;

		for (int i = 0; i < outposts; ++i) 
			for (int j = i+1; j< outposts; ++j)
				if (distances[i][j] > max_distance) {
					max_distance = distances[i][j];
					a = i;
					b = j;
				}

		distances[a][b] = 0;
		distances[b][a] = 0;


	}


	std::vector<float> dist;

	std::sort(dist.begin(), dist.end());

	return dist[dist.size() - 1 - satelites / 2];
}

int main() {

	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i) 
		std::cout << solve() << std::endl;
}