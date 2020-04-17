#include <iostream>
#include <vector>
#include <numeric>

int solve(int pocet_balicku) {

	std::vector<int> balicky(pocet_balicku);

	for (int i = 0; i < pocet_balicku; ++i)
		std::cin >> balicky[i];

	int const pocet_bonbonku = std::accumulate(balicky.begin(), balicky.end(), 0);

	int const cilovy_pocet = pocet_bonbonku / pocet_balicku;

	if (cilovy_pocet * pocet_balicku != pocet_bonbonku)
		return -1;

	int pocet_kroku = 0;

	for (int pocet_v_balicku : balicky)
		if (pocet_v_balicku < cilovy_pocet)
			pocet_kroku += cilovy_pocet - pocet_v_balicku;


	return pocet_kroku;
}


int main(int, char**) {

	int packets;
	while (true) {
		std::cin >> packets;
		if (packets == -1) break;

		std::cout << solve(packets) << '\n';

	}

}
