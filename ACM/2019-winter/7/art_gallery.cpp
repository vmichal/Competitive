#include <iostream>
#include <utility>
#include <cmath>
#include <vector>


struct vector {
	int x, y;
};

typedef vector point;

inline vector operator-(vector end, vector start) {
	return { end.x - start.x, end.y - start.y };
}


bool is_left(point X, point A, vector AB) {

	if (AB.y == 0)
		return (X.y < A.y) == (AB.x < 0);
	else if (AB.x == 0)
		return (X.x < A.x) == (AB.y > 0);

	float const x = float(X.x - A.x) / AB.x;
	float const y = float(X.y - A.y) / AB.y;

	return (x - y < 0) == ((AB.y < 0) == (AB.x < 0));
}


bool solve(int const N) {
	std::vector<point> points(N + 2);
	for (int i = 0; i < N; ++i)
		std::cin >> points[i].x >> points[i].y;
	points[N] = points[0];
	points[N + 1] = points[1];


	bool const turning_left = is_left(points[2], points[0], points[1] - points[0]);

	for (int i = 2; i < points.size(); ++i) {

		if (is_left(points[i], points[i - 2], points[i - 1] - points[i - 2]) != turning_left)
			return true;
	}

	return false;

}


int main(int, char**) {
	int N;
	while (std::cin >> N && N)
		std::cout << (solve(N) ? "Yes\n" : "No\n");

}