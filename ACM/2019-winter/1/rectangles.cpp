#include <iostream>
#include <cmath>

int main(int, char**) {

	int N;
	std::cin >> N;

	int count = 0;

	for (int rows = 1; rows <= std::sqrt(N); ++rows)
		count += (N / rows) - rows + 1;

	std::cout << count << '\n';
}