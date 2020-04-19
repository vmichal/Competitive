//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=155&page=show_problem&problem=2870
//11770 Lighting away

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <stack>

//Rùzné stavy vrcholu bìhem DFS
enum class state {
	fresh = 0,
	open,
	closed
};

void dfs(int const root, std::vector<std::vector<int>> const& lights, std::vector<state>& states, std::unordered_set<int>& switches) {
	/*DFSkem projdi všechny èerstvé nenavštívené vrcholy dostupné z rootu.*/
	std::stack<int> stack;
	stack.push(root);
	states[root] = state::open;

	for (; !stack.empty();) {
		//Vezmi uzel ze zásobníku, zkontroluj všechny jeho potomky. Pokud ještì nìjaký nebyl uzavøen, pøidej jej na zásobník 

		int const current = stack.top();
		bool has_fresh_child = false;

		for (int const neighbour : lights[current])

			//Pokud jsme narazili na uzavøený vrchol, jenž mùže být v množinì vypínaèù, odstraòme ho, protože jej umíme rozstvítit na dálku z rootu.
			if (states[neighbour] == state::closed)
				switches.erase(neighbour);

		//Èerstvé vrcholy otevøeme a strèíme na zásobník
			else if (states[neighbour] == state::fresh) {
				states[neighbour] = state::open;
				stack.push(neighbour);
				has_fresh_child = true;
			}

		//Pokud jsme našli nìjakého fresh potomka, vìnujme se nejdøíve jemu 
		if (has_fresh_child)
			continue;

		stack.pop();
		states[current] = state::closed;
	}
}


int solve_one() {

	/*Input: Two integers node_count a edge_count; následováno edge_count øádky.*/
	int N, E;
	std::cin >> N >> E;

	//graf udržovaný jako seznam sousednosti. lights[i] je pole všech svìtýlek, jež se rozsvítí, rozsvítí-li se svìtýlko i
	std::vector<std::vector<int>> lights(N + 1); 
	std::vector<state> states(N + 1, state::fresh); //pole DFS stavù
	std::vector<bool> has_parent(N + 1, false); //has_parent[i] iff existuje jiný vrchol j takový, že existuje hrana j -> i
	std::unordered_set<int> switches; //množina vypínaèù
	//První index v kontejnerech vynechávám, protože úloha èísluje vrcholy 1..N

	for (int i = 0; i < E; ++i) {
		int a, b;
		std::cin >> a >> b;
		lights[a].push_back(b);
		has_parent[b] = true;
	}

	//Procházím všechny vrcholy. Jakmile nìjaký z nich nemá rodièe, poté se neumí 
	//sám rozsvítit øetìzovou reakcí. Musíme jej pøidat mezi vypínaèe
	for (int i = 1; i <= N; ++i)
		if (!has_parent[i]) {
			switches.insert(i);
			dfs(i, lights, states, switches);
		}

	for (;;) {
		//Najdi libovolný ještì nenavštívený vrchol
		auto const unvisited_ptr = std::find(states.begin() + 1, states.end(), state::fresh);
		if (unvisited_ptr == states.end()) //pokud takový neexistuje, konèí algoritmus.
			return switches.size();

		//Získej poøadové èíslo vrcholu z offsetu jeho ukazatele
		int const vertex = std::distance(states.begin(), unvisited_ptr);

		/*Pøidej jej mezi vypínaèe a spus z nìj DFS. Tento vrchol možná ve výsledku nebude vypínaèem, 
		protože když jej dosáhneme bìhem DFS z nìjakého jiného vrcholu, poté bude z množiny vypínaèù odstranìn.*/
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