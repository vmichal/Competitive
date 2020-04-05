#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct activity {
	int start, end;
	char who;
};

std::string solve() {

	int N;
	std::cin >> N;

	std::vector<activity> activities(N);


	for (auto& ac : activities)
		std::cin >> ac.start >> ac.end;

	std::vector<activity*> sorted;
	sorted.resize(N);

	std::transform(activities.begin(), activities.end(), sorted.begin(), [](auto &a) {return &a;});

	std::sort(sorted.begin(), sorted.end(), [](activity* a, activity*b) {return a->start < b->start;});


	int end_time[2] = { 0,0 };
	char names[] = "CJ";

	for (auto* ac : sorted) {

		if (ac->start < end_time[0] && ac->start< end_time[1])
			return "IMPOSSIBLE";

		for (int i = 0; i < 2; i++)
			if (ac->start >= end_time[i]) {
				end_time[i] = ac->end;
				ac->who = names[i];
				break;
			}
	}

	std::string result;
	result.reserve(N);

	for (auto & ac : activities)
		result += ac.who;

	return result;
}

int main(int, char**) {

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i)
		std::cout << "Case #" << i << ": " << solve() << '\n';

};