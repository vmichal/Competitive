//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=149&page=show_problem&problem=1184

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <stack>


void form_tree(int const root, std::vector<std::vector<int>>& tree) {
	for (int const nei : tree[root]) {
		tree[nei].erase(std::find(tree[nei].begin(), tree[nei].end(), root));
		form_tree(nei, tree);
	}
}


std::vector<std::vector<int>> read_input(int const N) {
	std::vector<std::vector<int>> tree(N + 1);
	for (int i = 1; i <= N; ++i) {
		int capacity;
		std::cin >> capacity;

		tree[i].resize(capacity);
		for (int& neighbour : tree[i])
			std::cin >> neighbour;
	}
	return tree;
}

int solve(int const N) {


	std::vector<std::vector<int>> tree = read_input(N);

	if (N <= 3)
		return 1;

	int const root = std::distance(tree.begin(), std::max_element(tree.begin(), tree.end(), [](std::vector<int>const& a, std::vector<int> const& b) { return a.size() < b.size(); }));

	form_tree(root, tree);

	std::vector<int> prices(N + 1, -1);
	for (int i = 1; i <= N; ++i)
		if (tree[i].empty())
			prices[i] = 0; //all leaves have value of 0

	std::stack<int> s;
	s.push(root);

	for (; !s.empty();) {
		int const current = s.top();

		bool unknown_child = false;
		for (int const child : tree[current])
			if (prices[child] == -1) {
				s.push(child);
				unknown_child = true;
			}
		if (unknown_child)
			continue;

		int is_present = 1;
		for (int const child : tree[current])
			is_present += prices[child];

		int is_not_present = tree[current].size();
		for (int const child : tree[current])
			for (int const grandchild : tree[child])
				is_not_present += prices[grandchild];

		prices[current] = std::min(is_present, is_not_present);
		s.pop();
	}


	return prices[root];

}

int main(int, char**) {

	for (;;) {

		int N;
		std::cin >> N;
		if (N == 0)
			break;
		std::cout << solve(N) << '\n';
	}
}