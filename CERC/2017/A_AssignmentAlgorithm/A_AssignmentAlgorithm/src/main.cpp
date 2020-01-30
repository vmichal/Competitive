//http://cerc.hsin.hr/tasks/cerc2017_problems.pdf
#include <iostream>
#include <vector>
#include <algorithm>

struct line;

constexpr unsigned empty = 0, reserved = 100, aisle = 101;
std::vector<line> lines;
line * exits[3];
std::size_t zatizeni[2];

struct line {
	unsigned seats_[11];
	std::size_t vzdalenost_ = 0, free_ = 9;
};

std::istream& operator>>(std::istream& stream, line& line) {
	char c;
	for (auto ptr = std::begin(line.seats_), end = std::end(line.seats_); ptr != end; ++ptr)
		switch (std::cin >> c, c) {
			case '#':
				*ptr = reserved;
				--line.free_;
				break;
			case '-':
				*ptr = empty;
				break;
			case '.':
				*ptr = aisle;
				break;
			default:
				std::cout << "err, read " << int(c) << std::endl;
		}
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const line& line) {
	for (unsigned seat : line.seats_)
		switch (seat) {
			case reserved:
				stream << '#';
				break;
			case empty:
				stream << '-';
				break;
			case aisle:
				stream << '.';
				break;
			default:
				stream << char('a' - 1 + seat);
		}
	return stream;
}

std::vector<line> nactiVstup(int n, int r) {
	lines.resize(r + 3);
	for (line& line : lines)
		std::cin >> line;
	for (int i = 0; i < 3; i++)
		exits[i] = &lines[i * (r / 2 + 1)];
	int distance = 1;
	line *beg, *end;
	for (beg = exits[0] + 1, end = exits[1] - 1; beg < end; ++beg, --end)
		beg->vzdalenost_ = end->vzdalenost_ = distance++;
	if (beg == end)
		beg->vzdalenost_ = distance;
	distance = 1;
	for (beg = exits[1] + 1, end = exits[2] - 1; beg < end; ++beg, --end)
		beg->vzdalenost_ = end->vzdalenost_ = distance++;
	if (beg == end)
		beg->vzdalenost_ = distance;
	return lines;
}

enum strana {
	left, right
};

void propoctiZatizeni() {
	for (line& line : lines) {
		unsigned count = 0;
		for (int i = 0; i < 5; i++)
			if (line.seats_[i] == empty)
				
		zatizeni[left] += count;
		count = 5;
		for (int i = 6; i < 11; i++)
			if (line.seats_[i] != empty)
				--count;
		zatizeni[right] += count;
	}
}

int main(int argc, char ** argv) {
	int r, n;
	std::cin >> r >> n;

	lines = nactiVstup(n, r);

	propoctiZatizeni();

	std::vector<line*> options;
	options.reserve(r);
	for (int j = 0; j < 2; j++)
		if ((exits[j] + 1)->free_)
			options.push_back(exits[j] + 1);

	//loopy
	int passenger = 1;
	if (options.size() == 2) {
		for (; passenger <= n; ++passenger) {
			line * current = options[0]->free_ >= options[1]->free_ ? options[0] : options[1];

		}
	}


	for (; passenger <= n && options.size(); ++passenger) {

	}

	for (line& line : lines)
		std::cout << line << std::endl;;
}