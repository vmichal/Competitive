//https://atcoder.jp/contests/abc163/tasks/abc163_c
#include <vector>
#include <iostream>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> subs(N + 1);
	for (int i = 1; i < N; ++i) {
		int boss;
		std::cin >> boss;
		++subs[boss];
	}

	for (int i = 1; i <= N; ++i)
		std::cout << subs[i] << '\n';

}