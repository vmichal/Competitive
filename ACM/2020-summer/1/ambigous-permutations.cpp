#include <vector>
#include <iostream>
#include <algorithm>

bool solve(int N) {

	std::vector<int> permutation;
	permutation.resize(N + 1);

	for (int i = 1; i <= N; ++i)
		std::cin >> permutation[i];

	for (int i = 1; i <= N; ++i)
		if (permutation[permutation[i]] != i)
			return false;

	return true;
}

int main(int, char**) {

	for (int size; std::cin >> size && size; )
		std::cout << (solve(size) ? "ambiguous" : "not ambiguous") << std::endl;
}