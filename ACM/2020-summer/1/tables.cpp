#include <iostream>
#include <vector>
#include <algorithm>

int main() {

	int box_count, screws_per_table, table_count;
	std::cin >> box_count >> screws_per_table >> table_count;

	int required_screws = screws_per_table * table_count;

	std::vector<int> boxes;
	boxes.resize(box_count);
	for (int& box : boxes)
		std::cin >> box;

	std::sort(boxes.begin(), boxes.end());

	box_count = 0;
	for (auto begin = boxes.rbegin(), end = boxes.rend(); begin != end && required_screws > 0; ++begin) {
		++box_count;
		required_screws -= *begin;
	}
	std::cout << box_count << std::endl;


}