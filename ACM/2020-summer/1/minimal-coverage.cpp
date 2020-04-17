#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct segment {

	int left, right;

};

void solve() {

	int M;
	std::cin >> M;

	std::vector<segment> segments;

	int min_left = std::numeric_limits<int>::max(), max_right = std::numeric_limits<int>::min();

	for (;;) {
		int left, right;
		std::cin >> left >> right;
		if (left == 0 && right == 0)
			break;
		if (right > 0 && left < M) {
			segments.push_back({ left, right });
			if (left < min_left)
				min_left = left;
			if (right > max_right)
				max_right = right;
		}
	}


	std::sort(segments.begin(), segments.end(), 
		[](segment a, segment b) { 
			return a.left != b.left ? a.left < b.left : a.right < b.right;
		});

	if (segments.empty() || min_left > 0 || max_right < M) {
		std::cout << "0\n";
		return;
	}

	auto find_next_segment = [&segments](int left_bound, std::vector<segment>::iterator iterator) {
		auto used = iterator;
		for (auto segment = iterator + 1; segment != segments.end() && segment->left <= left_bound; ++segment)
			if (segment->right > used->right)
				used = segment;
		return used;
	};

	auto used_segment = find_next_segment(0, segments.begin());

	std::vector<segment> used;
	for (int position = 0; ; used_segment = find_next_segment(position, std::next(used_segment))) {
		if (position < used_segment->left) {
			used.clear();
			break;
		}
		used.push_back(*used_segment);
		position = used_segment->right;
		if (position >= M)
			break;
	}

	if (used.empty()) {
		std::cout << "0\n";
		return;
	}

	std::cout << used.size() << '\n';
	for (auto segment : used)
		std::cout << segment.left << ' ' << segment.right << '\n';
}

int main(int, char**) {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; ++i) {
		solve();
		if (i < T - 1) std::cout << '\n';
	}
}