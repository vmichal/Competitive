#include <iostream>
#include <string>

bool solve() {
	std::string S;
	std::cin >> S;

	//The string must be a palindrome, 
	//because the reversed string has to b the same
	for (int i = 0, last = S.size() - 1; i <= last; ++i)
		if (S[i] != S[last - i])
			return false;

	return true;
}


int main(int, char**) {
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
		std::cout << (solve() ? "YES" : "NO") << std::endl;
}