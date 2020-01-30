//https://projecteuler.net/problem=17

/*If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.*/

#include "stdafx.h"
#include <iostream>

using namespace std;


int main() {
	int one = 3, two = 3, three = 5, four = 4, five = 4, six = 3, seven = 5, eight = 5, nine = 4, ten = 3, eleven = 6, twelve = 6, thirteen = 8, fourteen = 8, fifteen = 7, sixteen = 7,
		seventeen = 9, eighteen = 8, nineteen = 8, twenty = 6, thirty = 6, forty = 5, fifty = 5, sixty = 5, seventy = 7, eighty = 6, ninety = 6, hundred = 10, thousand = 8;

	int desitka = one + two + three + four + five + six + seven + eight + nine;	 //36

	int teen = eleven + twelve + thirteen + fourteen + fifteen + sixteen + seventeen + eighteen + nineteen;
	int ty = twenty + thirty + forty + fifty + sixty + seventy + eighty + ninety;

	int soucet = 9 * desitka;
	soucet += teen;
	soucet += 10 * ty;// 1 - 100	  
	cout << soucet << endl;
	soucet *= 10;
	cout << soucet << endl;
	soucet += 900 * hundred;
	cout << soucet << endl;
	soucet += 100 * desitka;
	cout << soucet << endl;
	soucet += one + thousand;
	cout << soucet << endl;


    return 0;
}

