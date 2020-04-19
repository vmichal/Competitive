#include "stdafx.h"
#include <iostream>
using namespace std;

void Solve() {
	int n;
	cin >> n;
	int *pole = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> pole[i];
	}
	for (int i = 1; i < n; i++) {
		if (pole[i] > pole[i - 1] + 3) {
			pole[0] = -1;
		}				
	}
	cout << (pole[0]==1 ? "ne" : "ano" ) << endl;
	delete[] pole;
}

int main() {
	int pocetTestu;
	cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++)
		Solve();
	return 0;
}