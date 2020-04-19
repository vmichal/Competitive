// Problem 10 - Sum of primes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;


int main() {
	fstream file("prvocisla.txt");
	unsigned long long cislo = 0, soucet = 0;

	file >> cislo;
	while (cislo<2000000) {
		soucet += cislo;
		file >> cislo;	 
	}
	cout << soucet << endl;
	file.close();

	
    return 0;
}

