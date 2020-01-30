// Problem 22 - Names scores.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void seradVector(vector<string> *vec) {
	for (int i = 0; i < vec->size(); i++) {
		for (vector<string>::iterator iter = vec->begin(); iter != vec->end() - 1; iter++) {
			if (*iter > *(iter + 1)) {
				string s = *iter;
				*iter = *(iter + 1);
				*(iter + 1) = s;
			}					
		}
	}							
}

int hodnotaStringu(string s) {
	int soucet = s.length();
	for (int i = 0; i < s.length(); i++) {
		soucet += s[i] - 'A';
	}
	return soucet;		
}

int main() {
	ifstream file("names.txt");
	vector<string> jmena;
	while (!file.eof()) {
		char znak;
		file >> znak;
		if (znak == '"') {
			string jmeno;
			file >> znak;
			while (znak != '"') {
				jmeno.push_back(znak);
				file >> znak;
			}
			jmena.push_back(jmeno);
		}	
	}
	file.close();

	cout << jmena.size() << endl;
	seradVector(&jmena);

	unsigned long long soucet = 0;

	for (int i = 0;i<jmena.size();i++) 
		soucet += hodnotaStringu(jmena[i]) * (i+1);

	cout << soucet << endl;

    return 0;
}

