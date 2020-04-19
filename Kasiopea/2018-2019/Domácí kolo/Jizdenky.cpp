//https://kasiopea.matfyz.cz/soutez/A/
#include <iostream>
			 
void solve() {
	int day, week;
	std::cin >> day >> day >> week;
	std::cout << (day * 7 < week ? "jednodenni" : "tydenni") << std::endl;
}

int main(int argc, char ** argv) {
	int T;
	for (std::cin >> T; T; --T)
		solve();
}