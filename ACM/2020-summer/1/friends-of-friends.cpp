//https://www.spoj.com/problems/FACEFRND/

#include <iostream>
#include <set>
#include <vector>


int solve() {
	int N;
	std::cin >> N;

	std::vector<int> friends(N);
	std::set<int> ids;

	for (int& f : friends) {
		int count;
		std::cin >> f >> count;
		for (int i = 0, person; i < count; ++i)
			std::cin >> person, ids.insert(person);
	}

	for (int f : friends)
		ids.erase(f);

	return ids.size();
}

int main() {
	std::cout << solve() << '\n';
}