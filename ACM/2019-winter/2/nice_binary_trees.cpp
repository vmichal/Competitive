#include <iostream>
#include <string>

std::string input;
std::string::iterator current;


int traverse(int depth) {

	int deepest = depth;
	for (int i = 0; i < 2; i++)
		if (*++current == 'n') {
			int subtree = traverse(depth + 1);
			if (subtree > deepest)
				deepest = subtree;
		}
	return deepest;
}


int solve() {

	std::getline(std::cin, input);

	current = input.begin();

	return *current == 'l' ? 0 : traverse(1);

}

int main(int, char**) {

	int t;
	std::cin >> t;
	std::cin.ignore(10, '\n');


	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}