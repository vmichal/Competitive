#include <cassert>
#include <iostream>
#include <future>
#include <vector>
#include <condition_variable>
#include <mutex>  
#include <deque>
#include <map>
#include <set>
#include <numeric>	  
#include <execution>

std::mutex mutex;
std::condition_variable condition_variable;
bool readingFinished;

struct forma {
	int vyska_, sirka_;
	bool processed_ = false, inQueue_ = false;

	bool operator<(const forma& rhs) const {
		return vyska_ < rhs.vyska_;
	}

	bool operator==(const forma& rhs) const {
		return vyska_ == rhs.vyska_ && sirka_ == rhs.sirka_;
	}

	void swap() {
		std::swap(vyska_, sirka_);
	}

	bool isCtverec() const {
		return vyska_ == sirka_;
	}
};

std::vector<forma> readInput() {
	std::vector<forma> formy;
	{
		std::lock_guard guard(mutex);
		int N;
		std::cin >> N;
		formy.resize(N);
		for (forma& forma : formy) {
			std::cin >> forma.vyska_ >> forma.sirka_;
			if (forma.vyska_ < forma.sirka_)
				forma.swap();
		}
	}
	readingFinished = true;
	condition_variable.notify_all();  		 //reading finished, next thread can start
	return formy;
}

unsigned long long int solve() {
	std::vector<forma> formy = readInput();
	std::sort(std::execution::par_unseq, formy.begin(), formy.end());

	std::map<unsigned, std::set<forma*>> vysky;
	for (forma& f : formy) {
		vysky[f.sirka_].emplace(&f);
		vysky[f.vyska_].emplace(&f);
	}

	std::queue<forma*> fronta;

	if (std::all_of(vysky.begin(), vysky.end(), [](const decltype(*vysky.begin())& pair) -> bool {
		return pair.second.size() == 2;
	}))
		return std::accumulate(vysky.begin(), vysky.end(), 0ull, [](unsigned long long tmp, decltype(*vysky.end())& pair) ->unsigned long long {
			return tmp + pair.first;
		});
	if (forma& forma = formy.back(); forma.isCtverec()) {
		fronta.push(&forma);			 //pokud je poslední forma ètverec, push do fronty
		forma.inQueue_ = true;
	}

	for (auto iter = formy.begin(), next = std::next(iter), end = formy.end(); next != end; ++iter, ++next) {
		if (iter->isCtverec()) {        //ètvercová forma
			assert(!iter->inQueue_ && !iter->processed_);
			fronta.push(&*iter);
			iter->inQueue_ = true;
		}
		else if (*next == *iter) { 		  //dvì stejné							 
			assert(!iter->inQueue_ && !iter->processed_);
			assert(!next->inQueue_ && !next->processed_);
			fronta.push(&*iter);
			iter->inQueue_ = true;
			vysky.at(iter->vyska_).erase(&*iter);

			next->swap();
			fronta.push(&*next);
			next->inQueue_ = true;
			vysky.at(next->vyska_).erase(&*next);

			iter = next++;		//step one forward
		}
	}
//fronta obsahuje pointery na formy, které již jsou obsaženy jen v sirky[iter->sirka] a jejichž sousedi jsou ke smazání


	while (true) {
		forma* forma;
		if (fronta.size()) {
			forma = fronta.front();
			fronta.pop();
			assert(forma->inQueue_ && !forma->processed_);
			forma->inQueue_ = false;
			if (vysky.empty()) {
				assert(fronta.empty());
				continue;
			}
		}
		else if (vysky.size()) {
			auto iter = std::find_if(vysky.rbegin(), vysky.rend(), [](const decltype(*vysky.begin())& pair) -> bool {
				return pair.second.size() == 1;
			});
			assert(iter != vysky.rend());
			const auto &[vyska, set] = *iter;
			forma = *set.begin();
			assert(!forma->inQueue_ && !forma->processed_);
			if (vyska != forma->vyska_)
				forma->swap();
			vysky.erase(vyska);
		}
		else
			break;

		forma->processed_ = true;

		std::set<struct forma*>& sousedi = vysky.at(forma->sirka_);
		sousedi.erase(forma);
		for (auto iter : sousedi) {
			assert(!iter->processed_);
			if (iter->inQueue_) {
				assert(iter->vyska_ != forma->vyska_);
				continue;
			}
			if (iter->sirka_ == forma->sirka_)
				iter->swap();
			fronta.push(iter);
			iter->inQueue_ = true;
		}
		vysky.erase(forma->sirka_);
	}


	return std::accumulate(formy.begin(), formy.end(), 0ull, [](unsigned long long val, const forma& f) {
		return val + f.vyska_;
	});
}

int main() {
	int T;
	std::cin >> T;
	for (; T; T--)
		std::cout << solve() << std::endl;
	/*std::vector<std::future<unsigned long long int>> results;
	results.reserve(T);
	readingFinished = false;
	std::unique_lock<std::mutex> lock(mutex);
	for (; T; T--) {
		results.emplace_back(std::async(std::launch::async, solve));
		condition_variable.wait(lock, []() { return readingFinished; });
		readingFinished = false;
	}

	for (auto& result : results) {
		while (!result.valid());
		std::cout << result.get() << std::endl;
	} */
}