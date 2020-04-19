#include <iostream>
#include <string>

std::string solve() {

	int dragon, absorptions, lightnings;
	std::cin >> dragon >> absorptions >> lightnings;

	int const lighting_damage = lightnings * 10;

	if (dragon <= lighting_damage)
		return "YES";

	for (int i = 0; i < absorptions; ++i)
		dragon = dragon / 2 + 10;

	if (dragon <= lighting_damage)
		return "YES";
	else
		return "NO";
}

int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i)
		std::cout << solve() << std::endl;
}