#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

void solve(std::string const& line) {

	std::istringstream stream{ line };

	int width, height, time, vertical_bounce, horizontal_bounce;

	stream >> width >> height >> time >> vertical_bounce >> horizontal_bounce;

	double y = height * horizontal_bounce;
	double x = width * vertical_bounce;

	double hypot = std::hypot(x, y);


	double speed = hypot / time;

	double angle = std::atan(y / x) / std::acos(-1) * 180;

	std::cout << std::fixed << std::setprecision(2) << angle << ' ' << std::setprecision(2) << speed << '\n';
	
}

int main(int, char**) {

	while (true) {
		std::string line;
		std::getline(std::cin, line);
		if (line.front() == '0')
			break;

		solve(line);
	}

}
