#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int dimension_count;

struct box {
	int dimensions_[10];
	int index;

	bool fits_into(box const& other) const {
		for (int i = 0; i < dimension_count; ++i)
			if (dimensions_[i] >= other.dimensions_[i])
				return false;
		return true;
	}

	bool operator<(box const& other) const {
		for (int i = 0; i < dimension_count; ++i)
			if (dimensions_[i] < other.dimensions_[i])
				return true;
			else if (dimensions_[i] > other.dimensions_[i])
				return false;
		return false;
	}


	void sort() {
		for (int remaining_unsorted = dimension_count; remaining_unsorted > 0; --remaining_unsorted)
			for (int j = 1; j < remaining_unsorted; ++j)
				if (dimensions_[j - 1] > dimensions_[j])
					std::swap(dimensions_[j - 1], dimensions_[j]);
	}
};


std::vector<box> read_boxes() {
	int N;
	std::cin >> N >> dimension_count;
	if (!std::cin)
		return {};
	std::vector<box> boxes(N);
	for (int box = 0; box < N; ++box) {
		boxes[box].index = box + 1;
		for (int dimension = 0; dimension < dimension_count; ++dimension)
			std::cin >> boxes[box].dimensions_[dimension];
		boxes[box].sort();
	}
	std::sort(boxes.begin(), boxes.end());
	return boxes;
}

std::vector<int> find_lis(std::vector<box> const& boxes) {
	int lengths[32] = { 0 };
	int predecessors[32] = { 0 };

	for (int box = 0; box < boxes.size(); ++box) {

		lengths[box] = 0;
		predecessors[box] = -1;

		for (int i = 0; i < box; ++i)
			if (lengths[i] > lengths[box] && boxes[i].fits_into(boxes[box])) {
				lengths[box] = lengths[i];
				predecessors[box] = i;
			}
		++lengths[box];
	}

	int end_of_longest = 0;
	for (int i = 1; i < boxes.size(); ++i)
		if (lengths[i] > lengths[end_of_longest])
			end_of_longest = i;

	std::vector<int> lis;
	for (int box = end_of_longest; box != -1; box = predecessors[box])
		lis.push_back(box);
	std::reverse(lis.begin(), lis.end());
	return lis;
}

void solve() {

	auto const boxes = read_boxes();
	if (boxes.empty())
		return;


	auto const lis = find_lis(boxes);


	std::cout << lis.size() << '\n';
	for (int box : lis)
		std::cout << boxes[box].index << ' ';
	std::cout << '\n';

}

int main(int, char**) {
	while (std::cin)
		solve();
}