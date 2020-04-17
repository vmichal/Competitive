#include <iostream>

int digit_sum(int n) {
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}


int solve() {

	int n;
	std::cin >> n;
	int multiple = n;
	for (; digit_sum(multiple) != n; multiple += n);
	return multiple;

}


int main(int, char**) {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}