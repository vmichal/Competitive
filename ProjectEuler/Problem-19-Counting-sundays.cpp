//https://projecteuler.net/problem=19

/*You are given the following information, but you may prefer to do some research for yourself. FAKKA JÙ, MÍ NO RÍSRÈ
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?*/

#include <string>
#include <vector>
#include <array>
#include <iostream>

constexpr std::array<const char*, 7> dayNames{
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday",
	"sunday"
};

std::string dateFormat = "d.m.y";
int day = -1;
bool verbose;


constexpr int jePrestupny(unsigned rok) {
	return (rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0);
}

void printHelp() {
	std::cout << "USAGE .exe [OPTIONS]...\n\n"
		"Count all days in range [beginning, end) (=end excluded and do some shenanigans with them. Shurely comes in handy\n"
		"OPTIONS:\n"
		"\t-h[elp]: display this message\n"
		"\t-f[ormat]: specifies the format of given date strings.\n"
		"\t\tRecognized symbols are 'd', 'm' and 'y' for days, months and years respectively, every value has to be specified exactly.\n"
		"\t\tThe format is specified by using A SINGLE CHAR followed by delimiter in order to make this command usable past year 9999 kappa.\n"
		"\t\tThe default is \"d.m.y\" for formats like dd.mm.yyyy\n"
		"\t-v[erbose]: display verbose output\n"

}

bool tryParseDay(std::string den) {
	day = std::stoi(den);
	if (!day) {
		std::for_each(den.begin(), den.end(), [](char &c) {
			if (isupper(static_cast<unsigned char>(c)))
				c -= 'a' - 'A';
		});
		do {
			for (int i = 0; i < 7; i++)
				for (std::string currName = dayNames[i]; currName.size(); currName.pop_back())
					if (!den.compare(currName)) {
						day = i;
						std::cout << "Your enormous stupidity of typing '" << den << "' as a name of day is truly unbelievable"
							",\nenough data has been provided to suppose that '" << dayNames[day] << "' was the expected day.\n";
						return true;
					}
		} while (den.size());
		std::cout << "Err parsing day.\n";
		return false;
	}
	return true;
}

bool validateParams(std::vector<std::string> params) {
	if (params.empty())
		printHelp();
	for (auto begin = params.begin(), end = params.end(); begin != end; ++begin) {
		const std::string& str = *begin;
		if (!str.compare("-h") || !str.compare("-help")) {
			printHelp();
			return false;
		}
		if (!str.compare("-f") || !str.compare("-format")) {
			dateFormat = *++begin;
			continue;
		}
		if (!str.compare("-d") || !str.compare("-day")) {
			if (!tryParseDay(std::move(*++begin)))
				return false;
			continue;
		}
		if (!str.compare("-v") || !str.compare("-verbose")) {
			verbose = true;
			continue;
		}


	}
	return true;
}



int main(int argc, char **argv) {
	std::vector<std::string> params;
	params.resize(argc);
	for (int i = 1; i < argc; ++i)
		params.emplace_back(argv[i]);
	if (!validateParams(std::move(params)))
		return 1;



}