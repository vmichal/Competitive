//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=196&page=show_problem&problem=2010

#include <vector>
#include <iostream>

constexpr int max = 80;

unsigned results[max] = { 0 };

unsigned solve(int N) {
	if (results[N])
		return results[N];

	if (N == 1) {
		results[N] = 1;
		return solve(N);
	}

	std::vector<int> taken(N), not_taken(N);

	taken[0] = not_taken[0] = 1;
	taken[1] = not_taken[1] = 1;

	for (int i = 2; i < N - 1; ++i) {
		taken[i] = not_taken[i - 1];
		not_taken[i] = taken[i - 1] + taken[i - 2];
	}


	results[N] = taken[N - 2] + not_taken[N - 2];
	return solve(N);
}

int main() {

	for (int N; std::cin >> N;)
		std::cout << solve(N) << '\n';

}