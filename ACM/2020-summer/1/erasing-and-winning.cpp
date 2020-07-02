//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2486

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

constexpr char dummy = 'x';

bool solve() {
	int N, D;
	std::cin >> N >> D;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (N == 0 && D == 0)
		return false;

	std::string line;
	std::getline(std::cin, line);

	while (line.back() == ' ')
		line.pop_back();

	for (int i = 1; D && i < line.size(); ++i)
		if (line[i - 1] < line[i]) {
			line.erase(line.begin() + i - 1);
			--D;
			i -= (i > 1) ? 2 : 1;
		}

	auto const new_end = std::remove_if(line.begin(), line.end(), std::bind(std::equal_to<char>{}, std::placeholders::_1, dummy));
	line.erase(new_end, line.end());

	if (D) {

		std::vector<int> indices[10];
		for (auto& vec : indices)
			vec.reserve(N);

		for (int i = 0; i < line.size(); ++i)
			indices[line[i] - '0'].push_back(i);

		for (int i = 0; i <= 10; ++i)
			if (indices[i].size() > D) {
				indices[i].resize(D);
				for (int index : indices[i])
					line[index] = dummy;
				break;
			}
			else {
				D -= indices[i].size();
				for (int index : indices[i])
					line[index] = dummy;
			}

		auto const new_end = std::remove_if(line.begin(), line.end(), std::bind(std::equal_to<char>{}, std::placeholders::_1, dummy));
		line.erase(new_end, line.end());
	}

	std::cout << line << '\n';

	return true;
}

int main() {
	for (; solve(););
}
