#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>

#define NO_SOLUTION return "*"

#if 0
int N;
std::cin >> N;

std::vector<std::string> patterns_storage(N);
std::vector<std::string_view> views(N);
std::vector<std::ptrdiff_t> suffixes(N);


for (int i = 0; i < N; i++) {
	std::string& str = patterns_storage[i];
	std::cin >> str;
	views[i] = str;
}

auto const strip_trailing_asterisks = [&views]() {
	while (std::all_of(views.begin(), views.end(), [](auto const view) {return view.back() == '*'; }))
		for (std::string_view& view : views)
			view.remove_suffix(1);
};

strip_trailing_asterisks();

while (true) {


	char const last_character = views.front().back();

	for (std::string_view& view : views)
		if (view.back() != last_character)
			NO_SOLUTION;
		else
			view.remove_suffix(1);

	if (std::any_of(views.begin(), views.end(), std::mem_fn(std::string_view::empty)))
		for (std::string_view const view : views)
			if (!view.empty() && view.find_first_not_of('*') != std::string_view::npos)
				NO_SOLUTION;

	strip_trailing_asterisks();

}
#endif

void remove_prefix(std::string & str, int many) {

	str = str.substr(many);

}

void remove_suffix(std::string & str, int many) {
	str = str.substr(0,str.size() - many);
}

std::string solve() {

	int N;
	std::cin >> N;

	std::vector<std::string> patterns(N);
	std::vector<std::pair<std::ptrdiff_t, std::ptrdiff_t>> literal_lengths;
	literal_lengths.reserve(N);

	for (std::string& str : patterns) {
		std::cin >> str;

		auto const prefix = std::find(str.begin(), str.end(), '*');
		auto const suffix = std::find(str.rbegin(), str.rend(), '*');

		literal_lengths.push_back({ std::distance(str.begin(), prefix), std::distance(str.rbegin(), suffix) });
	}


	auto const pref_longest_iter = std::max_element(literal_lengths.cbegin(), literal_lengths.cend(), [](auto const a, auto const b) { return a.first < b.first; });
	auto const suff_longest_iter = std::max_element(literal_lengths.cbegin(), literal_lengths.cend(), [](auto const a, auto const b) { return a.second < b.second; });

	std::string const prefix = patterns[std::distance(literal_lengths.cbegin(), pref_longest_iter)].substr(0, pref_longest_iter->first);
	std::string suffix = patterns[std::distance(literal_lengths.cbegin(), suff_longest_iter)];
	suffix = suffix.substr(suffix.size() - suff_longest_iter->second);

	for (std::string const& str : patterns) {

		auto const comparison_pref = std::mismatch(prefix.cbegin(), prefix.cend(), str.cbegin(), str.cend());
		if (comparison_pref.second != str.cend() && *comparison_pref.second != '*')
			NO_SOLUTION;

		auto const comparison_suf = std::mismatch(suffix.crbegin(), suffix.crend(), str.crbegin(), str.crend());
		if (comparison_suf.second != str.crend() && *comparison_suf.second != '*')
			NO_SOLUTION;

	}
	for (int i = 0; i < N; ++i) {
		remove_prefix(patterns[i], literal_lengths[i].first);
		remove_suffix(patterns[i], literal_lengths[i].second);
	}

	//Now all patterns are not empty and both starting and ending in a wildcard. We can take advantage of this
	//By concatenating what remains

	std::string result;
	result.reserve(10'000);
	result += prefix;

	for (std::string const& str : patterns)
		result += str;

	result.erase(std::remove(result.begin(), result.end(), '*'), result.end());

	result += suffix;

	return result;
}


int main(int, char**) {

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i)
		std::cout << "Case #" << i << ": " << solve() << std::endl;

}