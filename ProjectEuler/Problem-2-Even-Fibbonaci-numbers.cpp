//https://projecteuler.net/problem=2
#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2) {
		cout << "Použití .exe maximum" << endl;  
		return 1;
	}
	cout << "Popiss:"<<endl<< "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms." << endl;
	
	int maximum = atoi(argv[1]);

	int a = 1, b = 2, sum = 0;
	while (b < maximum) {
		if (b % 2 == 0) {	
			sum += b;
		}
		b += a;
		a = b - a;
	}
	cout << "Suma sudých èísel fibbonaciho sekvence menších než "<<maximum <<" je "<<sum<< endl;	 
    return 0;
}

