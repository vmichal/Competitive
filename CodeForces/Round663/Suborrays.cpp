#include <iostream>
#include <vector>
#include <string>

int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i) {
		int n;
		std::cin >> n;
		std::cout << 1;
		for (int j = 2; j <= n; ++j)
			std::cout << ' ' << j;
		std::cout << '\n';
	}
}