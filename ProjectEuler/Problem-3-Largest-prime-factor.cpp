//https://projecteuler.net/problem=3
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> NactiPrvocisla(int maximum) {	
	vector<int> vec;
	fstream file("prvocisla.txt");
	int cislo = 0;
	while (cislo <= maximum) {
		file >> cislo;
		vec.push_back(cislo);
	}
	file.close();
	return vec;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Použítí : .exe cislo_k_rozlozeni" << endl;	
		return 1;
	}
	long long cislo = atoi(argv[1]);
	cout << "Popis: What is the largest prime factor of the number " << cislo << "?\t=>\t";
	vector<int> prvocisla = NactiPrvocisla(sqrt(cislo)+1);

	int index = 0;
	while (prvocisla[index] != cislo) {
		if (cislo % prvocisla[index] == 0) {
			cislo /= prvocisla[index];
		}
		else {
			index++;
		}
	}
	cout << prvocisla[index] << endl;
    return 0;
}

