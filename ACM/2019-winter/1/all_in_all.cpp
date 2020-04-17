#include <iostream>
#include <string>

bool solve(std::string const& sub, std::string const& seq) {

	auto searched = sub.begin();
	for (char c : seq)
		if (c == *searched) {
			++searched;
			if (searched == sub.end())
				return true;
		}
	return false;

}

int main(int, char**) {

	std::string line;

	while (std::cin) {
		std::string sub, seq;
		std::cin >> sub >> seq;
		if (sub.empty() || seq.empty())
			break;

		std::cout << (solve(sub, seq) ? "Yes\n" : "No\n");
	}
}
