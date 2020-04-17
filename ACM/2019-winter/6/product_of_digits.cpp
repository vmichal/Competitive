#include <iostream>
#include <string>
#include <numeric>
#include <iterator>

std::string solve(int N) {

	int factors[10] = { 0 };

	while (N > 1) {
		if (N % 9 == 0) {
			factors[9]++;
			N /= 9;
		}
		else if (N % 8 == 0) {
			factors[8]++;
			N /= 8;
		}
		else if (N % 7 == 0) {
			factors[7]++;
			N /= 7;
		}
		else if (N % 6 == 0) {
			factors[6]++;
			N /= 6;
		}
		else if (N % 5 == 0) {
			factors[5]++;
			N /= 5;
		}
		else if (N % 4 == 0) {
			factors[4]++;
			N /= 4;
		}
		else if (N % 3 == 0) {
			factors[3]++;
			N /= 3;
		}
		else if (N % 2 == 0) {
			factors[2]++;
			N /= 2;
		}
		else
			return "-1";
	}

	std::string result;
	result.reserve(std::accumulate(std::begin(factors), std::end(factors), 0));

	for (int i = 2; i <10; ++i)
		result.append(factors[i], '0'+i);
	return result.empty() ? std::string{char('0'+N)} : result;
}




int main() {

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int N;
		std::cin >> N;
		std::cout << solve(N) << '\n';
	}
}