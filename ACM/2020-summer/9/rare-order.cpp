#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <iterator>

struct letter {
	char name;
	std::set<char> precedes;
	std::set<char> succeeds;

};

static std::map<char, letter> letter_map;

void extract_knowledge(std::vector<std::string>::iterator begin, std::vector<std::string>::iterator end) {

	if (std::distance(begin, end) < 2)
		return;

	std::vector<char> seen;

	for (auto b = begin, e = std::find_if(b + 1, end, [&](std::string const& str) { return str.back() != b->back(); });
		b != end;
		b = e, e = std::find_if(b, end, [&](std::string const& str) { return str.back() != b->back(); })) {

		seen.push_back(b->back());

		for (auto iter = b; iter != e; ++iter) {
			assert(!iter->empty());
			iter->pop_back();
		}
		b = std::find_if_not(b, e, [](std::string const& str) { return str.empty(); });

		extract_knowledge(b, e);
	}

	for (int i = 0; i < seen.size(); i++)
		for (int j = i + 1; j < seen.size(); ++j) {
			letter_map[seen[i]].precedes.insert(seen[j]);
			letter_map[seen[j]].succeeds.insert(seen[i]);
		}

}

std::string solve(std::vector<std::string>& words) {
	extract_knowledge(words.begin(), words.end());


	for (std::pair<char const, letter>& p : letter_map)
		p.second.name = p.first;

	std::string alphabet;

	for (; !letter_map.empty();) {
		auto const next = std::find_if(letter_map.begin(), letter_map.end(), [](std::pair<const char, letter> const& a) -> bool { return a.second.succeeds.empty(); });
		assert(next != letter_map.end());
		assert(std::find_if(std::next(next), letter_map.end(), [](std::pair<const char, letter> const& a) -> bool { return a.second.succeeds.empty(); }) == letter_map.end());

		alphabet.push_back(next->first);

		for (char const c : next->second.precedes)
			letter_map[c].succeeds.erase(next->first);

		letter_map.erase(next->first);
	}

	return alphabet;

}

int main(int, char**) {


	for (;;) {
		std::string line;
		std::cin >> line;
		if (line.empty())
			break;
		std::reverse(line.begin(), line.end());

		std::vector<std::string> words;
		words.push_back(line);

		for (;;) {
			std::cin >> line;
			if (line.front() == '#' && line.size() == 1)
				break;
			std::reverse(line.begin(), line.end());
			words.emplace_back(std::move(line));
		}

		std::cout << solve(words) << std::endl;
	}
}