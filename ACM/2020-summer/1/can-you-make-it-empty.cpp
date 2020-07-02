//https://www.spoj.com/problems/EMTY2/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

bool solve() {

	std::string line;
	std::getline(std::cin, line);
	int zeros = 0;

	for (auto it = line.rbegin(); it != line.rend(); ++it)
		if (*it == '1')
			if (zeros < 2)
				return false;
			else
				zeros -= 2;
		else
			++zeros;

	return zeros == 0;
}

int main() {
	int T;
	std::cin >> T;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 1; i <= T; ++i)
		std::cout << "Case " << i << ": " << (solve() ? "yes" : "no") << '\n';
}