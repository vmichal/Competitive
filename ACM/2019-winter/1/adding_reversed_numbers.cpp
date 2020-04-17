#include <iostream>

int reverse(int a) {
	int result = 0;
	while (a) {
		result = (result * 10) + a % 10;
		a /= 10;
	}
	return result;
}

int add_reversed(int a, int b) {

	int result = reverse(a) + reverse(b);

	return reverse(result);

}


int main(int, char**) {

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int a, b;
		std::cin >> a >> b;
		std::cout << add_reversed(a, b) <<std::endl;
	}
	return 0;
}