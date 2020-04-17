#if 0
#include <iostream>
#include <vector>
#include <map>
#include <queue> 
#include <set>
int N;

std::vector<std::map<int, int>> debts(1000);
std::vector<std::set<int>> dluznici(1000);

void read_input() {
	std::cin >> N;
	for (int bank = 0; bank < N; ++bank) {
		dluznici[bank].clear();
		debts[bank].clear();
	}

	for (int bank = 0; bank < N; ++bank)
		for (int to = 0; to < N; ++to) {
			int money;
			std::cin >> money;
			if (money) {
				dluznici[to].insert(bank);
				debts[bank][to] = money;
			}
		}
}

int count_money() {

	int sum = 0;
	for (auto const& bank : debts)
		for (auto const& debt : bank)
			sum += debt.second;
	return sum;
}

void simplify_reciprocal_debts() {



	for (int self = 0; self < N; ++self)
		for (int other = 0; other < self; ++other) {
			int& to_other = debts[self][other],
				to_me = debts[other][self];

			if (to_other == to_me) {
				debts[self].erase(other);
				debts[other].erase(self);
				dluznici[other].erase(self);
				dluznici[self].erase(other);
			}
			else if (to_other > to_me) {
				to_other -= to_me;
				debts[other].erase(self);
				dluznici[self].erase(other);
			}
			else {
				to_me -= to_other;
				debts[self].erase(other);
				dluznici[other].erase(self);
			}
		}

}

void simplify_transitive_debt() {
	std::queue<int> singles;

	for (int i = 0; i < N; ++i)
		if (debts[i].size() == 1 && dluznici[i].size() == 1)
			singles.push(i);

	//eliminate A --> B --> C
	while (!singles.empty()) {
		int const middle = singles.front();
		singles.pop();

		int const start = *dluznici[middle].begin();
		int const end = debts[middle].begin()->first;

		int to = debts[start][middle];
		int from = debts[middle][end];

		if (from == to) {
			debts[middle].erase(end);
			debts[start].erase(middle);
			dluznici[middle].erase(start);
			dluznici[end].erase(middle);
			if (debts[end].size() == 1 && dluznici[end].size() == 1)
				singles.push(end);
		}

	}
}

void simplify_triangles() {

	std::vector<std::pair<int, int>> to_del;

	for (int middle = 0; middle < N; ++middle)
		for (int start : dluznici[middle])
			for (auto const& end : debts[middle])
				if (dluznici[end.first].count(start)) {
					debts[]

				}


}

void simplify() {

	simplify_reciprocal_debts();

	simplify_transitive_debt();

	simplify_triangles();




}
#endif

#include <iostream>
#include <vector>
int main() {

	std::ios_base::sync_with_stdio(false);


	for (int i = 1; ; ++i) {
		int N;
		std::cin >> N;
		if (N == 0)
			break;
		std::vector<int> debts(N);

		int before = 0;

		for (int from = 0; from < N; ++from)
			for (int to = 0; to < N; ++to) {
				int debt;
				std::cin >> debt;
				before += debt;
				debts[from] += debt;
				debts[to] -= debt;
			}
		int after = 0;
		for (int const d : debts)
			if (d > 0)
				after += d;
		std::cout << i << ". " << before << ' ' << after << '\n';
	}


}

