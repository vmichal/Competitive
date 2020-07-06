//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=193&page=show_problem&problem=1170
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <iterator>

std::vector<int> cache;

int solve() {
	int n, m;
	std::cin >> n >> m;
	if (!std::cin)
		exit(0);

	if (n <= 1)
		return n;

	unsigned const mod = 1 << m;



	std::array<unsigned, 6> arr;
	arr[0] = 0; arr[1] = 1; arr[2] = 1;
	arr[3] = 2; arr[4] = 3; arr[5] = 5;

	for (n -= 5; n > 5; n -= 6) {
		arr[0] = (arr[4] + arr[5]) % mod;
		arr[1] = (arr[5] + arr[0]) % mod;
		arr[2] = (arr[0] + arr[1]) % mod;
		arr[3] = (arr[1] + arr[2]) % mod;
		arr[4] = (arr[2] + arr[3]) % mod;
		arr[5] = (arr[3] + arr[4]) % mod;
	}

	return arr[5 - n];

}

int main() {
	cache.reserve(1 << 20);
	cache.push_back(0);
	cache.push_back(1);
	cache.push_back(1);
	cache.push_back(2);
	cache.push_back(3);
	cache.push_back(5);
	cache.push_back(8);
	cache.push_back(13);
	cache.push_back(21);
	for (;;)
		std::cout << solve() << '\n';
}