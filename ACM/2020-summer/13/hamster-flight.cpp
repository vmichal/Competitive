//SPOJ problem
//https://www.spoj.com/problems/HAMSTER1/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdio>

double value(double v, double k1, double k2, double phi) {
	constexpr double g = 10.0;
	return std::pow(v, 2) / g * (k1 * std::sin(2 * phi) + k2 / 2 * std::pow(std::sin(phi), 2));

}

void solve() {

	int v, k1, k2;
	std::cin >> v >> k1 >> k2;

	double const pi = std::acos(-1);

	double phi;
	if (k1 == 0)
		phi = pi / 2;
	else if (k2 == 0)
		phi = pi / 4;
	else
		phi = (pi - std::atan(4 * k1 / k2)) / 2;

	printf("%.3f %.3f\n", phi, value(v, k1, k2, phi));
}
int main(int argc, char** argv) {

	int T;
	std::cin >> T;
	for (int i = 0; i < T; ++i)
		solve();

}