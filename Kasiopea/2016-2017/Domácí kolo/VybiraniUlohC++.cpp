// VybiraniUlohC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void Solve() {
	int pocetUloh;
	std::cin >> pocetUloh;
	int maximum = 0, index = 0, mistni;
	for (int i = 1; i <= pocetUloh; i++) {
		std::cin >> mistni;
		if (mistni > maximum) {
			maximum = mistni;
			index = i;
		}						
	}
	std::cout << index << "\n";
}

int main()
{
	int pocetTestu;
	std::cin >> pocetTestu;
	for (int i = 0; i < pocetTestu; i++) {
		Solve();
	}
}

