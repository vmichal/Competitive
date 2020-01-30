//https://projecteuler.net/problem=6

#include "stdafx.h"
#include <iostream>
using namespace std;


int main() {
	int soucet = 0;
	int ctverce = 0;
	for (int i = 1; i <= 100; i++) {
		soucet += i;
		ctverce += i*i;
	}
	cout << soucet*soucet - ctverce << endl;

}

