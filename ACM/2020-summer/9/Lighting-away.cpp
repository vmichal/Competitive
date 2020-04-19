//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=155&page=show_problem&problem=2870
//11770 Lighting away

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <stack>

//R�zn� stavy vrcholu b�hem DFS
enum class state {
	fresh = 0,
	open,
	closed
};

void dfs(int const root, std::vector<std::vector<int>> const& lights, std::vector<state>& states, std::unordered_set<int>& switches) {
	/*DFSkem projdi v�echny �erstv� nenav�t�ven� vrcholy dostupn� z rootu.*/
	std::stack<int> stack;
	stack.push(root);
	states[root] = state::open;

	for (; !stack.empty();) {
		//Vezmi uzel ze z�sobn�ku, zkontroluj v�echny jeho potomky. Pokud je�t� n�jak� nebyl uzav�en, p�idej jej na z�sobn�k 

		int const current = stack.top();
		bool has_fresh_child = false;

		for (int const neighbour : lights[current])

			//Pokud jsme narazili na uzav�en� vrchol, jen� m��e b�t v mno�in� vyp�na��, odstra�me ho, proto�e jej um�me rozstv�tit na d�lku z rootu.
			if (states[neighbour] == state::closed)
				switches.erase(neighbour);

		//�erstv� vrcholy otev�eme a str��me na z�sobn�k
			else if (states[neighbour] == state::fresh) {
				states[neighbour] = state::open;
				stack.push(neighbour);
				has_fresh_child = true;
			}

		//Pokud jsme na�li n�jak�ho fresh potomka, v�nujme se nejd��ve jemu 
		if (has_fresh_child)
			continue;

		stack.pop();
		states[current] = state::closed;
	}
}


int solve_one() {

	/*Input: Two integers node_count a edge_count; n�sledov�no edge_count ��dky.*/
	int N, E;
	std::cin >> N >> E;

	//graf udr�ovan� jako seznam sousednosti. lights[i] je pole v�ech sv�t�lek, je� se rozsv�t�, rozsv�t�-li se sv�t�lko i
	std::vector<std::vector<int>> lights(N + 1); 
	std::vector<state> states(N + 1, state::fresh); //pole DFS stav�
	std::vector<bool> has_parent(N + 1, false); //has_parent[i] iff existuje jin� vrchol j takov�, �e existuje hrana j -> i
	std::unordered_set<int> switches; //mno�ina vyp�na��
	//Prvn� index v kontejnerech vynech�v�m, proto�e �loha ��sluje vrcholy 1..N

	for (int i = 0; i < E; ++i) {
		int a, b;
		std::cin >> a >> b;
		lights[a].push_back(b);
		has_parent[b] = true;
	}

	//Proch�z�m v�echny vrcholy. Jakmile n�jak� z nich nem� rodi�e, pot� se neum� 
	//s�m rozsv�tit �et�zovou reakc�. Mus�me jej p�idat mezi vyp�na�e
	for (int i = 1; i <= N; ++i)
		if (!has_parent[i]) {
			switches.insert(i);
			dfs(i, lights, states, switches);
		}

	for (;;) {
		//Najdi libovoln� je�t� nenav�t�ven� vrchol
		auto const unvisited_ptr = std::find(states.begin() + 1, states.end(), state::fresh);
		if (unvisited_ptr == states.end()) //pokud takov� neexistuje, kon�� algoritmus.
			return switches.size();

		//Z�skej po�adov� ��slo vrcholu z offsetu jeho ukazatele
		int const vertex = std::distance(states.begin(), unvisited_ptr);

		/*P�idej jej mezi vyp�na�e a spus� z n�j DFS. Tento vrchol mo�n� ve v�sledku nebude vyp�na�em, 
		proto�e kdy� jej dos�hneme b�hem DFS z n�jak�ho jin�ho vrcholu, pot� bude z mno�iny vyp�na�� odstran�n.*/
		switches.insert(vertex);
		dfs(vertex, lights, states, switches);
	}
}

int main() {
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i)
		std::cout << "Case " << i << ": " << solve_one() << '\n';
}