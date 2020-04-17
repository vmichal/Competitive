#include <iostream>
#include <cmath>
#include <iomanip>


int main(int, char**) {

	int width, height, time, vertical, horizontal;

	while (std::cin >> width >> height >> time >> vertical >> horizontal) {
		if (time == 0)
			break;

		double const hypotenuse = std::hypot(height*horizontal, width * vertical);
		double const speed = hypotenuse / time;
		double const angle = std::acos((width*vertical)/hypotenuse) * 180 / (atan(1)*4);



		std::cout << std::fixed << std::setprecision(2) <<angle << ' ' << std::setprecision(2)<< speed  <<std::endl;

	}



}