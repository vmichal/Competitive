#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int pocetGladiatoru;
	cin >> pocetGladiatoru;
	int** gladiatori = new int*[pocetGladiatoru];
	for (int i = 0; i < pocetGladiatoru; i++) {
		gladiatori[i] = new int[3];
		gladiatori[i][0] = i;
		cin >> gladiatori[i][1] >> gladiatori[i][2];
	}



}

