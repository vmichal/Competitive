#include <iostream>
#include <vector>


struct mesto;

struct cesta {
	mesto * start_, cil_;
	unsigned long long hodnota_ = 0, lide_ = 0;
}

struct mesto {
	int lide_, vzdalenost_;
	mesto* dalsi_;
	std::vector<mesto*> sousedni_;
	std::vector<cesta> cesty_;

	unsigned long long int celkemLidi() {
		unsigned long long int res = lide_;
		for (cesta& c : cesty_)
			lide_ += c.lide_;
		return lide_;
	}

	unsigned long long int celkemHodnota() {
		unsigned long long int res = celkemLidi();
		for (cesta &c : cesty_)
			res += c.hodnota;
		return res;
	}
};




std::vector<mesto> readInput() {
	int N, M;
	std::cin >> N >> M;
	std::vector<mesto> mesta(N);
	mesto * begin = mesta.data();;
	for (int i = 0;i<M;i++) {
		int u, v;
		std::cin >> u >> v;
		mesta[u].sousedni_.push_back(begin + v);
		mesta[v].sousedni_.push_back(begin + u);		
	}
	for (int i = 1;i<N;i++) {
		mesto& m = mesta[i];
		int dalsi;
		std::cin >> m.lide_ >> dalsi;
		m.dalsi_ = begin + dalsi;
		assert(std::find(m.sousedni_.begin(), m.sousedni_.end(), m.dalsi_) != m.sousedni_.end());
	}
	return mesta;
}

void inicializujCesty(mesto* mesto, int vzdalenost) {
	mesto->vzdalenost = vzdalenost;
	for (mesto * soused : mesto.sousedi_)
		if (soused->ukazatel == mesto) {
			inicializujCesty(soused, vzdalenost + 1);
			mesto->cesty_.emplace_back(soused, mesto);
			cesta& c = mesto->cesty.back();
			c.lide_ = soused->celkemLidi();
			c.hodnota_ = soused->celkemHodnota(); 
		}
}

std::pair<int, int> solve() {
	auto mesta = readInput();
	inicializujCesty(&mesta.front(), 0);




}



int main() {
	int T;
	for (std::cin >> T; T; T--) {
		auto [kde, kam] = solve();
		std::cout << kde << ' ';
		if (kde) 
			std::cout << kam;
		std::cout << std::endl; 	
	}
}