#include <iostream>
#include <cstring>

int const coins[] = { 1,5,10,25,50 };

long long cache[5][30001] = { };


unsigned long long count_ways(int const remaining, int const coin) {

	if (remaining == 0 || coin == 0)
		return 1;

	if (cache[coin][remaining] != -1)
		return cache[coin][remaining];

	if (remaining < coins[coin])
		return cache[coin][remaining] = count_ways(remaining, coin - 1);

	return cache[coin][remaining] = count_ways(remaining, coin - 1) + count_ways(remaining - coins[coin], coin);
}

int main(int, char**) {

	for (int i = 0; i < 5; ++i)
		std::memset(cache[i], -1, sizeof(cache[i]));

	while (true) {
		int num;
		std::cin >> num;
		if (!std::cin)
			break;
#if 0
		std::cout << count_ways(num, 4) << '\n';
#endif
		unsigned long long const ways = count_ways(num, sizeof(coins) / sizeof(int) - 1);
		if (ways == 1)
			std::cout << "There is only 1 way to produce " << num << " cents change.\n";
		else
			std::cout << "There are " << ways << " ways to produce " << num << " cents change.\n";
	}
}