//https://kasiopea.matfyz.cz/soutez/D/?
#include <iostream>
#include <map>
#include <future>
#include <mutex>
#include <iomanip>
#include <condition_variable>


//Dynamické øešení
/*Dynamic solution

struct rybnicek {
int index_, pritok_ = 1;
double chybi_;

rybnicek(double chybi, int index) : index_(index), chybi_(chybi) {}

};

std::pair<double, double> solve() {
int N;
std::cin >> N;

std::list<rybnicek> rybnicky;
for (int i = 1; i <= N; i++) {
int kapacita;
std::cin >> kapacita;
rybnicky.emplace_back(kapacita, i);
}
readingFinished = true;
conditionVariable.notify_all();
std::vector<std::list<rybnicek>::iterator> plne;
plne.reserve(N);
double posledniTime = 0.0, vsechnyTime = 0.0;

while (rybnicky.size()) {
double timeToFill = 1'000'000'000.0;
for (std::list<rybnicek>::iterator begin = rybnicky.begin(), end = rybnicky.end(); begin != end; ++begin) {
double timeLeft = begin->chybi_ / begin->pritok_;
double delta = timeLeft - timeToFill;
if (abs(delta) < 0.01)
plne.emplace_back(begin);
else if (delta < 0.0) {
timeToFill = timeLeft;
plne.clear();
plne.push_back(begin);
}
}
vsechnyTime += timeToFill;
for (rybnicek & r : rybnicky)
r.chybi_ -= r.pritok_* timeToFill;
for (auto iter : plne) {
if (iter->index_ == N)  //posledni
posledniTime = vsechnyTime;
else
if (auto next = std::next(iter); next != rybnicky.end())
next->pritok_ += iter->pritok_;   //zvìtši pøítok dalšího rybníèku
rybnicky.erase(iter);
}
}
return std::make_pair(posledniTime, vsechnyTime);
}

int main() {
int T;
std::vector<std::future<std::pair<double, double>>> results;
std::unique_lock<std::mutex> lock(mutex);

for (std::cin >> T; T; T--) {
readingFinished = false;
results.emplace_back(std::async(std::launch::async, solve));
conditionVariable.wait(lock, []() -> bool {return readingFinished; });
}
for (auto &future : results) {
while (!future.valid());
auto[posledniTime, vsechnyTime] = future.get();
printf("%.2f %.2f\n", posledniTime, vsechnyTime);
}
}
*/

std::condition_variable cond;
std::mutex mutex;
volatile bool readingFinished;



struct rybnicek {
	double kapacita_;
};

std::vector<rybnicek> readInput() {
	std::vector<rybnicek> rybnicky;
	{
		std::lock_guard<std::mutex> guard(mutex);
		int N;
		std::cin >> N;
		rybnicky.resize(N);
		for (rybnicek& ryb : rybnicky)
			std::cin >> ryb.kapacita_;
	}
	readingFinished = true;
	cond.notify_one();
	return rybnicky;
}

std::pair<double, double> solve() {
	std::vector<rybnicek> rybnicky = readInput();
	std::map<double, unsigned> casyPritoku;
	casyPritoku.emplace(rybnicky.front().kapacita_, 1);
	for (auto iter = std::next(rybnicky.begin()), end = rybnicky.end(); iter != end; ++iter) {
		rybnicek& ryb = *iter;
		if (auto lowest = casyPritoku.begin(); ryb.kapacita_ < lowest->first)
			casyPritoku.emplace(ryb.kapacita_, 1);
		else if (ryb.kapacita_ == lowest->first)
			++lowest->second;
		else {
			double time = 0.0;
			unsigned pritok = 1;
			for (; lowest != casyPritoku.end(); pritok += lowest->second, ++lowest) {
				if (double priteklo = (lowest->first - time) * pritok; priteklo < ryb.kapacita_) {
					ryb.kapacita_ -= priteklo;
					time = lowest->first;
				}
				else if (priteklo == ryb.kapacita_) {
					++lowest->second;
					break;
				}
				else {	   //priteklo > ryb.kapacita_
					time += ryb.kapacita_ / pritok;
					lowest = casyPritoku.emplace(time, pritok).first;
					break;
				}
			}
			casyPritoku.erase(casyPritoku.begin(), lowest);
			if (casyPritoku.empty()) {							 
				time += ryb.kapacita_ / pritok;
				lowest = casyPritoku.emplace(time, pritok).first;
			}
		}
	}
	return std::make_pair(casyPritoku.begin()->first, std::prev(casyPritoku.end())->first);
}

int main() {
	int T;
	for (std::cin >> T; T; T--) {
		const auto&[last, all] = solve();
		std::cout << std::fixed << std::setprecision(2) << last << " " << std::fixed << std::setprecision(2) << all << std::endl;
	}
	/*int T;
	std::cin >> T;
	std::vector<std::future<std::pair<double, double>>> results;
	results.reserve(T);
	readingFinished = false;
	std::unique_lock<std::mutex> lock(mutex);
	for (int i = 0; i < T; i++) {
		results.emplace_back(std::async(std::launch::async, solve));
		cond.wait(lock, []() { return readingFinished; });
		readingFinished = false;
	}

	for (int i = 0; i < T; i++) {
		while (!results[i].valid());
		auto res = results[i].get();
		printf("%.2f %.2f\n", res.first, res.second);
	} */
}