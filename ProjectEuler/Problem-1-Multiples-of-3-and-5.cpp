//https://projecteuler.net/problem=1

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 4) {										   
		cout << "Použití: .exe maximum cisloA cisloB." << endl;
		return 1;
	}
	cout << "Popis:" << endl;
	cout << "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23." << endl;
	cout << "Find the sum of all the multiples of 3 or 5 below 1000." << endl;
		
	int maximum = atoi(argv[1]);
	int cisloA = atoi(argv[2]);
	int cisloB = atoi(argv[3]);

	auto countDivisibleBy = [=](int n) mutable -> signed {
		maximum /= n;
		return (maximum * (maximum + 1)) / 2;
	};
	
	cout << "\nSuma pøirozených násobkù "<< cisloA << " nebo " << cisloB << " menších než "<<maximum << " je ";
	cout << countDivisibleBy(3)  + countDivisibleBy(5) - countDivisibleBy(15)<< endl;
    return 0;
}

