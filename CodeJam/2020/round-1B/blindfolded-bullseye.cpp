#include <string>
#include <iostream>
#include <cassert>
#include <array>
#include <vector>
#include <numeric>

#define _USE_MATH_DEFINES
#include <math.h>



int constexpr max = 1e9, min = 1e9;
int A, B;

enum class result {
	center, hit, miss, wrong
};

result communicate(int x, int y) {
	if (std::abs(x) > max || std::abs(y) > max)
		return result::miss;
	std::cout << x << ' ' << y << std::endl;
	//std::cerr << x << ' ' << y << std::endl;

	std::string response;
	std::cin >> response;

	//std::cerr << response << std::endl;

	switch (response.front()) {
	case 'W': exit(EXIT_FAILURE); break;
	case 'C': throw 42;
	case 'M': return result::miss;
	case 'H': return result::hit;
	}
	assert(false);
}

struct coord {
	int x, y;
};

constexpr coord operator+(coord a, coord b) {
	return { a.x + b.x, a.y + b.y };
}

constexpr coord operator/(coord a, int b) {
	return { a.x / b, a.y / b };
}



coord find_circle() {

	if (A > 7e8)
		return { 0,0 };

	std::vector<coord> hits;

	for (int y = 1; y <= 7; ++y)
		for (int x = 1; x <= 7; ++x) {
			coord c{ -max + x * (max / 4) , -max + y * (max / 4) };
			result const res = communicate(c.x, c.y);
			if (res == result::hit)
				hits.push_back(c);
		}

	for (coord& c : hits)
		c = c / hits.size();

	return std::accumulate(hits.begin(), hits.end(), coord{ 0,0 });
}


coord binary_search_up(coord current) {
	int const x = current.x;

	int low = current.y, high = max;

	auto const attempt = communicate(x, high);
	if (attempt == result::hit)
		return { x, high };

	while (low < high) {
		int const mid = (low + high) / 2 + 1;
		auto const res = communicate(x, mid);
		switch (res) {
		case result::hit:
			low = mid;
			break;
		case result::miss:
			high = mid - 1;
			break;
		}
	}
	return { x, low };
}

coord binary_search_down(coord current) {
	int const x = current.x;
	int low = -max, high = current.y;

	auto const attempt = communicate(x, low);
	if (attempt == result::hit)
		return { x, high };


	while (low < high) {
		int const mid = (low + high) / 2;
		auto const res = communicate(x, mid);
		switch (res) {
		case result::hit:
			high = mid - 1;
			break;
		case result::miss:
			low = mid;
			break;
		}
	}
	return { x, low };
}

coord binary_search_right(coord current) {
	int const y = current.y;
	int low = current.x, high = max;

	auto const attempt = communicate(high, y);
	if (attempt == result::hit)
		return { high, y };


	while (low < high) {
		int const mid = (low + high) / 2 + 1;
		auto const res = communicate(mid, y);
		switch (res) {
		case result::hit:
			low = mid;
			break;
		case result::miss:
			high = mid - 1;
			break;
		}
	}
	return { low, y };
}

coord binary_search_left(coord current) {
	int const y = current.y;
	int low = -max, high = current.y;

	auto const attempt = communicate(low, y);
	if (attempt == result::hit)
		return { low, y };

	while (low < high) {
		int const mid = (low + high) / 2;
		auto const res = communicate(mid, y);
		switch (res) {
		case result::hit:
			high = mid - 1;
			break;
		case result::miss:
			low = mid;
			break;
		}
	}
	return { low, y };
}

void solve() {
	auto const circle_point = find_circle();

	std::cerr << "Assuming [" << circle_point.x << ", " << circle_point.y << "] as center.\n";

	coord const up = binary_search_up(circle_point);
	coord const down = binary_search_down(circle_point);
	coord const left = binary_search_left(circle_point);
	coord const right = binary_search_right(circle_point);

	coord center;
	center.x = (left.x + right.x) / 2;
	center.y = (down.y + up.y) / 2;

	for (int y = -3; y < 4; ++y)
		for (int x = -3; x < 4; ++x)
			communicate(center.x + x, center.y + y);
}

int main() {

	int T;
	std::cin >> T >> A >> B;

	std::cin.ignore(1);
	for (int i = 1; i <= T; ++i)
		try {
		solve();
	}
	catch (...) {}
}