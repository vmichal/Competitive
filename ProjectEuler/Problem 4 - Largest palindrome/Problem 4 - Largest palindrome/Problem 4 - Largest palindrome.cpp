//https://projecteuler.net/problem=4

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

bool palindrom(int soucin) {
	for (int i = 0; i <= 2; i++) {
		int vyssi = (soucin / (int) pow(10, 5 - i)) % 10;
		int nizsi = (soucin / (int) pow(10, i)) % 10;
		if (vyssi != nizsi)
			return false;
	}
	return true; 	
}

int main() {
	vector<int> vec;
	for (int i = 999;i>=900; i--) {
		for (int j = 999;j>=i; j--) {
			if (palindrom(i*j)) {
				vec.push_back(i*j);
			}
		}
	}	
	int nejvetsi = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > nejvetsi) {
			nejvetsi = vec[i];
		}  
	}
	cout << nejvetsi << endl;
    return 1;
}

