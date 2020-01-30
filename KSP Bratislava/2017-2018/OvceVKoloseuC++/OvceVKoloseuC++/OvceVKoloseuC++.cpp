// OvceVKoloseuC++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int pocetOvci;
	cin >> pocetOvci;
	int* x = new int[pocetOvci];
	int* y = new int[pocetOvci];
	for (int i = 0; i < pocetOvci; i++) {
		cin >> x[i] >> y[i];
	}
    return 0;
}

