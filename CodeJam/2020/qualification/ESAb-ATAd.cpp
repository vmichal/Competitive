#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <array>

enum class value {
	unknown,
	zero,
	one
};

value operator~(value const v) {
	if (v == value::unknown)
		return value::unknown;
	return v == value::one ? value::zero : value::one;
}

value ask_for(int const i) {
	std::cout << i + 1 << std::endl;
	char input;
	std::cin >> input;
	if (input == 'N')
		exit(1);
	assert(input == '0' || input == '1');
	return input == '0' ? value::zero : value::one;
}

void guess_solution(std::vector<value> const& array) {

	for (value v : array) {
		assert(v != value::unknown);
		std::cout << (v == value::one ? '1' : '0');
	}
	std::cout << std::endl;

	char input;
	std::cin >> input;
	assert(input == 'N' || input == 'Y');

	if (input == 'N')
		exit(1);

}

int find_same(std::vector<value> const& array) {
	for (int i = 0; i < array.size(); ++i)
		if (array[i] != value::unknown && array[i] == array[array.size() - 1 - i])
			return i;
	return -1;
}

int find_neg(std::vector<value> const& array) {

	for (int i = 0; i < array.size(); ++i)
		if (array[i] != value::unknown && array[i] != array[array.size() - 1 - i])
			return i;
	return -1;
}

void solve(int const B) {

	std::vector<value> array(B, value::unknown);
	int trial = 1;


	for (int i = 0; i < 5; ++i) {
		array[i] = ask_for(i);
		array[B - 1 - i] = ask_for(B - 1 - i);
	}
	if (B <= 10) {
		guess_solution(array);
		return;
	}

	for (int upcoming_query = 11; upcoming_query < 150; upcoming_query += 2) {

		if (upcoming_query % 10 == 1) {

			int const same = find_same(array);
			int const neg = find_neg(array);


			if (same == -1 && neg == -1) { //huh?
				assert(false);
#if 0
				for (value& v : array)
					v = value::unknown;
				for (int i = 0; i < 5; ++i) {
					int const j = trial * 5 + i;
					array[j] = ask_for(j);
					array[B - 1 - j] = ask_for(B - 1 - j);
				}

				++trial;
				upcoming_query += 8;
				continue;
#endif
			}
			if (same != -1 && neg != -1) { //both okay, we can handle any modification

				assert(array[same] == array[array.size() - 1 - same]);
				assert(array[neg] != array[array.size() - 1 - neg]);

				value const new_same = ask_for(same); //here the fluctuation happens
				value const new_neg = ask_for(neg);

				if (new_same == array[same] && new_neg == array[neg]) {
					//nothing happened
				}
				else if (new_neg == array[neg]) {// both rotation and compl
					for (value& v : array)
						v = ~v;
					std::reverse(array.begin(), array.end());
				}
				else if (new_same == array[same]) {//rotation
					std::reverse(array.begin(), array.end());
				}
				else {//complement
					for (value& v : array)
						v = ~v;
				}

				assert(array[same] == new_same);
				assert(array[neg] == new_neg);

			}
			else if (neg != -1) { //all known values are negations of mirror image 
				assert(array[neg] != array[array.size() - 1 - neg]);

				value const new_neg = (ask_for(neg), ask_for(neg));

				if (new_neg != array[neg])
					std::reverse(array.begin(), array.end());
			}
			else {// same != -1 //all known values have same mirror image
				assert(same != -1);
				assert(array[same] == array[array.size() - 1 - same]);

				value const new_same = (ask_for(same), ask_for(same));

				if (new_same != array[same]) 
					for (value&v : array)
						v = ~v;
			}
		}
		else {

			auto const un = std::find(array.begin(), array.end(), value::unknown);
			assert(un != array.end());


			int const offset = std::distance(array.begin(), un);

			assert(array[offset] == value::unknown);
			assert(array[B - 1 - offset] == value::unknown);

			array[offset] = ask_for(offset);
			array[B - 1 - offset] = ask_for(B - 1 - offset);

			if (std::find(array.begin(), array.end(), value::unknown) == array.end()) {
				//There are no more unknown values, try to report solution
				guess_solution(array);
				return;
			}


		}
	}

	for (value& v : array)
		if (v == value::unknown) //We have to guess 
			v = value::zero;
	guess_solution(array);
}


int main(int, char**) {
	int T, B;
	std::cin >> T >> B;

	for (int i = 1; i <= T; i++)
		solve(B);
}