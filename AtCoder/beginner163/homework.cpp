//https://atcoder.jp/contests/abc163/tasks/abc163_b

#include <iostream>

int main() {
	int days, tasks;
	std::cin >> days >> tasks;

	for (int i = 0; i < tasks; ++i) {
		int a;
		std::cin >> a;
		days -= a;
	}
	if (days < 0)
		days = -1;
	std::cout << days << std::endl;
}