#include <iostream>
#include <iomanip>
#include <cstring> 
#include <cmath>

constexpr int coins[] = { 5,10,20,50,100,200,500,1000,2000,5000,10000};

long long cache[sizeof(coins) / sizeof(coins[0])][300 * 100 + 1];

#define ret(x) return cache[highest_coin_index][ammount] = x;

long long solve(int const ammount, int const highest_coin_index) {
	if (ammount == 0 || highest_coin_index == 0)
		ret(1);
	if (cache[highest_coin_index][ammount] != -1)
		return cache[highest_coin_index][ammount];

	if (coins[highest_coin_index] > ammount)
		ret(solve(ammount, highest_coin_index - 1));


	long long ways = 0;

	for (int left = ammount; left >= 0; left -= coins[highest_coin_index])
		ways += solve(left, highest_coin_index - 1);
	ret(ways);
}

int main(int, char**) {
	std::memset(cache, 0xff, sizeof(cache));
	float ammount;
	for (std::cin >> ammount; ammount != 0.0f; std::cin >> ammount)
		std::cout << std::fixed << std::setprecision(2) << std::right << std::setw(6)
		<< ammount << std::setw(17) << solve(static_cast<int>(std::round(ammount * 100)), sizeof(coins) / sizeof(coins[0]) - 1) << std::endl;


}
