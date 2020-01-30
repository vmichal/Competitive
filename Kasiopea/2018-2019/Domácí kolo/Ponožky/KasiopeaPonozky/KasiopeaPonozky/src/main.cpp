//https://kasiopea.matfyz.cz/soutez/B/
#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>


void solve() { 																															   
	int N, K;
	std::cin >> N >> K;
	std::vector<bool> licha(K, false);

	while (N--) {
		std::cin >> K;
		licha[--K].flip();
	}
	std::cout << std::accumulate(licha.begin(), licha.end(), 0, [](int count, bool b) ->int {return b ? count + 1 : count; }) << std::endl;
}



int main() {
	int T;

	for (std::cin >> T; T; T--)
		solve();

}	