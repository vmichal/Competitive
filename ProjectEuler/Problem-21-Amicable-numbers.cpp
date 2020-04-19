// https://projecteuler.net/problem=21

/*Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000000000

bool navstivenaCisla[MAX];

int sectiDelitele(int cislo) {
	int soucet = 0;
	for (int i = 1; i <= cislo / 2; i++)
		if (cislo % i == 0)
			soucet += i;
	return soucet;
}

int main() {
	for (int i = 0; i < MAX; i++)
		navstivenaCisla[i] = false;

	for (int i = 0; i < MAX; i++) {
		if (navstivenaCisla[i])
			continue;
		int soucet = sectiDelitele(i);
		int druhy = sectiDelitele(soucet);

		navstivenaCisla[i] = true;
		if (soucet < MAX)
			navstivenaCisla[soucet] = true;

		if (druhy == i && i != soucet) {	
			cout << i << "\t\t" << soucet << endl;
		}
	}											   
    return 0;
}

