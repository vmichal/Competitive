#include <iostream>


int main() {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i) {

		int health, divs, subs;
		std::cin >> health >> divs >>subs;

		int const lighting_damage = subs * 10;

		if (health <= lighting_damage) {
			std::cout << "YES\n";
			goto end;
		}

		for (int i = 0; i < divs; ++i) {
			health = health/2 + 10;
			if (health <= lighting_damage) {
				std::cout << "YES\n";
				goto end;
			}
		}
		std::cout << "NO\n";
		end:;
	}
}