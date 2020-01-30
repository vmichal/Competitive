//https://projecteuler.net/problem=9

/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	for (int a = 1; a < 1000; a++) {
		for (int b = a; b < 1000; b++) {
			for (int c =max(a,b) ; c < 1000; c++) {
				if (a*a + b*b == c*c && a + b + c == 1000) {
					cout << a*b*c << "="<<a<<"*"<<b<<"*"<<c << endl;
					return 0;
				}			 
			}
		}					 
	}

    return 1;
}

