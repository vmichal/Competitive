#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>

double solve(int h, int m) {
	if (h == 12)
		h = 0;

	double minute_angle = 6.0 * m;

	constexpr double day_minutes = 12 * 60;
	double current_time = h * 60 + m;
	double hour_angle = (current_time / day_minutes) * 360.0;

	double angle = std::abs(hour_angle - minute_angle);

	return angle > 180.0 ? 360.0 - angle : angle;

}

int main(int, char**) {
	std::string line;

	while (true) {
		int h, m;
		char colon;
		std::cin >> h >> colon >> m;
		if (m == 0 && h == 0)
			break;
		std::cout << std::fixed << std::setprecision(3) << solve(h, m) << '\n';

	}
}
