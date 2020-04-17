#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
#include <unordered_set>

int A, B, C;
#if 0
int a_value(int state) { return state >> 16; }
int b_value(int state) { return state & 0xffff; }
#endif

struct state {
	int a, b, steps;
};

#define hash(s_)  (s_.a << 16 | s_.b)

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


int solve() {
	std::cin >> A >> B >> C;

	if (C == 0)
		return 0;
	if (C == A || C == B)
		return 1;
	if (C > A && C > B)
		return -1;
	if (A == 0 || B == 0 || C % gcd(A, B))
		return -1;

	std::queue<state> queue;
	std::unordered_set<int> visited;
	queue.push({ 0,0,0 });
	visited.insert(0);

	while (!queue.empty()) {
		state const this_state = queue.front();
		queue.pop();
		if (this_state.a == C || this_state.b == C)
			return this_state.steps;

		int const& a = this_state.a;
		int const& b = this_state.b;
		int const s = this_state.steps + 1;
		state next_states[] = {
			//emptying and filling
			state{a == 0 ? A : 0,b,s}, state{a,b == 0 ? B : 0,s},
			//pouring from one to other

			state{a - std::min(B - b,  a), std::min(B, b + a),s}, //A to B
			state{std::min(A, a + b), b - std::min(A - a, b),s} //B to A
		};

		for (int i = 0; i < 4; i++)
			if (!visited.count(hash(next_states[i]))) {
				visited.insert(hash(next_states[i]));
				queue.push(next_states[i]);
			}
	}
	return -1;
}

int main(int, char**) {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i)
		std::cout << solve() << std::endl;
}












#if 0
std::set<int> checked_states;

int recurse(int a, int b) {
	if (a < 0 || b < 0 || checked_states.count(state{a, b)))
		return -1;

	if (a == C || b == C)
		return 0;
	checked_states.insert(state{a, b));

	int min = 1u << 30;
	bool path_found = false;
	auto check_min = [&](int moves) {
		if (moves == -1)
			return;
		path_found = true;
		++moves;
		if (moves < min)
			min = moves;
	};

	check_min(recurse(a == 0 ? A : 0, b));

	check_min(recurse(a, b == 0 ? B : 0));

	if (a > B - b)
		check_min(recurse(a - (B - b), B));
	else
		check_min(recurse(0, b + a));
	if (b > A - a)
		check_min(recurse(A, b - (A - a)));
	else
		check_min(recurse(a + b, 0));

	if (path_found) {
		checked_states.erase(state{a, b));
		return min;
	}
	else
		return -1;
}

int solve() {
	std::cin >> A >> B >> C;
	checked_states.clear();
	return recurse(0, 0);
}

int main(int, char**) {
	std::ios_base::sync_with_stdio(false);
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i)
		std::cout << solve() << '\n';
}
#endif