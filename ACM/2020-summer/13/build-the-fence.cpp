//SPOJ problem
//https://www.spoj.com/problems/BSHEEP/

#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>


struct coord {
	int x, y;
};

inline double length(coord const a) {
	return std::hypot(a.x, a.y);
}

inline constexpr coord operator-(coord const a, coord const b) {
	return { a.x - b.x, a.y - b.y };
}
inline constexpr bool operator==(coord const a, coord const b) {
	return a.x == b.x && a.y == b.y;
}

inline constexpr int dot_product(coord const a, coord const b) {
	return a.x * b.x + a.y * b.y;
}

inline double angle(coord const a, coord const b) {
	return std::acos(dot_product(a, b) / length(a) * length(b));
}

inline  double angle_from_x(coord const a) {
	if (a == coord{ 0, 0 })
		return 0.0;
	double const angle = std::acos(a.x / length(a));
	return a.y >= 0 ? angle : 2 * std::acos(-1) - angle;
}

constexpr bool more_botleft(coord const a, coord const b) {
	return a.y != b.y
		? a.y < b.y
		: a.x < b.x;
}

void solve() {
	int N;
	std::cin >> N;
	std::vector<coord> sheep(N);
	for (auto& coord : sheep)
		std::cin >> coord.x >> coord.y;

	if (N <= 1) {
		std::cout << "0.00\n1\n\n";
		return;
	}
	if (N == 2) {
		std::cout << std::setprecision(2) << std::fixed <<
			2 * std::hypot(sheep[0].x - sheep[1].x, sheep[0].y - sheep[1].y) << '\n';

		std::cout << (more_botleft(sheep[0], sheep[1]) ? "1 2" : "2 1") << "\n\n";
		return;
	}

	auto const maybe_start = std::min_element(sheep.begin(), sheep.end(), &more_botleft);
	auto const start = std::find(sheep.begin(), sheep.end(), *maybe_start);
	int const start_index = std::distance(sheep.begin(), start);

	std::vector<std::pair<double, int>> sorted(N);

	for (int i = 0; i < start_index; ++i)
		sorted[i] = { angle_from_x(sheep[i] - *start) , i };
	sorted[start_index] = { std::acos(-1), start_index };
	for (int i = start_index + 1; i < N; ++i)
		sorted[i] = { angle_from_x(sheep[i] - *start) , i };


	std::sort(sorted.begin(), sorted.end());

	std::vector<int> indices;
	std::vector<coord> edges;
	edges.reserve(10000);
	indices.reserve(10000);


	//convex hull
	indices.push_back(sorted.back().second);
	edges.push_back(*start);

	int i = 0;
	for (; i < sorted.size(); ) {
		if (sheep[sorted[i].second] == edges.back()) {
			i++;
			continue;
		}
		if (indices.size() == 1) {
			indices.push_back(sorted[i].second);
			edges.push_back(sheep[indices.back()]);
			++i;
			continue;
		}
		coord const previous = edges[edges.size() - 1] - edges[edges.size() - 2];
		coord const next = sheep[sorted[i].second] - edges[edges.size() - 1];

		if (angle_from_x(next) > angle_from_x(previous)) {
			indices.push_back(sorted[i].second);
			edges.push_back(sheep[indices.back()]);
			++i;
		}
		else {
			indices.pop_back();
			edges.pop_back();
		}
	}
	edges.pop_back();
	indices.pop_back();

	double circumference = std::hypot(edges.back().x - edges.front().x, edges.back().y - edges.front().y);
	for (int i = 1; i < edges.size(); ++i)
		circumference += std::hypot(edges[i].x - edges[i - 1].x, edges[i].y - edges[i - 1].y);

	std::cout << std::setprecision(2) << std::fixed << circumference << '\n';

	int const last = indices.back();
	indices.pop_back();
	for (int const index : indices)
		std::cout << index + 1 << ' ';
	std::cout << last + 1 << std::endl << std::endl;
}

int main(int, char**) {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i)
		solve();
}