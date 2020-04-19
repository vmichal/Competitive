#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int pocetNerovnosti, jamy = 0;
	cin >> pocetNerovnosti;
	for (int i = 0; i < pocetNerovnosti; i++) {		
		char nactene;
		cin >> nactene;
		if (nactene == '0')
			jamy++;				
	}			
	pocetNerovnosti = pocetNerovnosti - jamy * 2;				
	cout << (pocetNerovnosti > 0 ? pocetNerovnosti : -pocetNerovnosti) << endl; 	
}

