//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=196&page=show_problem&problem=1316
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <set>
#include <numeric>
#include <iterator>
#include <array>

/*Works, but has problems with precision


struct possibility {
	int num, denom;
};

long long double solve() {
	int p, q, r, s;
	if (!(std::cin >> p))
		exit(0);

	std::cin >> q >> r >> s;

	int pq = p - q, rs = r - s;

	int args[] = { p, rs, s, q, pq, r };
	long long double vals[] = { logs[p], logs[rs], logs[s],logs[q], logs[pq], logs[r] };


	possibility poss[] = {
		{0, 3},
		{0, 4},
		{0, 5},

		{1, 3},
		{1, 4},
		{1, 5},

		{2, 3},
		{2, 4},
		{2, 5}
	};

	std::sort(std::begin(poss), std::end(poss), [&args](possibility a, possibility b) {
		return std::abs(args[a.num] - args[a.denom]) < std::abs(args[b.num] - args[b.denom]);
		});

	bool touched[6] = { false };

	for (possibility p : poss) {
		int num = p.num, denom = p.denom;
		if (touched[denom] || touched[num])
			continue;

		if (args[num] == args[denom]) {
			args[num] = args[denom] = 0;
			vals[num] = vals[denom] = 0.0;
			touched[num] = touched[denom] = true;
		}
		else if (std::abs(args[num] - args[denom]) < 100)
			if (args[num] < args[denom]) {
				long long double counter = 0.0;
				for (int i = args[num] + 1; i <= args[denom]; ++i)
					counter += std::log(i);
				vals[denom] = counter;
				args[denom] -= args[num];
				args[num] = 0;

				vals[num] = 0.0;

				touched[num] = touched[denom] = true;
			}
			else {
				long long double counter = 0.0;
				for (int i = args[denom] + 1; i <= args[num]; ++i)
					counter += std::log(i);
				vals[num] = counter;

				args[num] -= args[denom];
				args[denom] = 0;

				vals[denom] = 0.0;

				touched[num] = touched[denom] = true;
			}
	}

	return std::exp(vals[0] - vals[3] + vals[1] - vals[4] + vals[2] - vals[5]);


}
*/

int gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

struct factorial {
	int first, last;
};

long double solve() {
	int p, q, r, s;
	if (!(std::cin >> p))
		exit(0);

	std::cin >> q >> r >> s;
	int pq = p - q, rs = r - s;

	std::array<int, 3> nums{ p, s, rs };
	std::array<int, 3> denoms{ q, r, pq };

	std::sort(nums.rbegin(), nums.rend());
	std::sort(denoms.rbegin(), denoms.rend());

	factorial numerators[3] = { {2, nums[0] }, {2, nums[1]}, {2, nums[2]} };
	factorial denominators[3] = { {2, denoms[0]}, {2, denoms[1]}, {2, denoms[2] } };

	for (int i = 0; i < 3; ++i) {
		factorial& num = numerators[i];
		factorial& denom = denominators[i];


		if (num.last == denom.last) {
			num.first = num.last = denom.first = denom.last = 1;
		}
		else if (num.last > denom.last) {
			num.first = denom.last + 1;
			denom.first = denom.last = 1;
		}
		else {
			denom.first = num.last + 1;
			num.first = num.last = 1;
		}
	}

	std::multiset<int> num;
	std::multiset<int> denom;

	for (factorial f : numerators)
		for (int i = f.first; i <= f.last; ++i)
			num.insert(i);
	for (factorial f : denominators)
		for (int i = f.first; i <= f.last; ++i)
			denom.insert(i);

	std::multiset<int> intersection;
	std::set_intersection(num.begin(), num.end(), denom.begin(), denom.end(), std::inserter(intersection, intersection.end()));

	auto const remove = [](std::multiset<int>& set, int val) {
		set.erase(set.find(val));
	};

	for (int i : intersection) {
		remove(num, i);
		remove(denom, i);
	}

	std::vector<int> n(num.begin(), num.end());
	std::vector<int> d(denom.begin(), denom.end());

	for (;;) {
		bool did_some = false;

		for (int& i : n)
			for (int& j : d) {
				int const g = gcd(i, j);
				if (g == 1)
					continue;
				i /= g;
				j /= g;
				did_some = true;
			}
		if (!did_some)
			break;
		n.erase(std::remove(n.begin(), n.end(), 1), n.end());
		d.erase(std::remove(d.begin(), d.end(), 1), d.end());
	}

	std::sort(n.begin(), n.end());
	std::sort(d.begin(), d.end());

	long double result = 1.0;

	for (; !n.empty() && !d.empty();)
		if (result < 1.0) {
			result *= n.back();
			n.pop_back();
		}
		else {
			result /= d.back();
			d.pop_back();
		}

	for (int i : d)
		result /= i;
	for (int i : n)
		result *= i;

	return result;



}

int main() {


	for (;;) {
		std::cout << std::fixed << std::setprecision(5) << solve() << std::endl;

	}
}