#include "stdafx.h"
#include <iostream>

void ProvedPorovnani(int * pocetPrvku, int const cislo, int * const koncePodmnozin) {
	if (cislo > koncePodmnozin[*pocetPrvku]) {
		++*pocetPrvku;
		koncePodmnozin[*pocetPrvku] = cislo;
		return;
	}
	for (int * ptr = &koncePodmnozin[*pocetPrvku]; ptr > koncePodmnozin; ptr--) {
		if (cislo>*ptr) {
			*(ptr + 1) = cislo;
			return;
		}
	}
}
using namespace std;

int main() {
	int n, e;
	cin >> n >> e;
	int *vstup = (int*)malloc(sizeof(int)*n);
	int *prvni = vstup;
	int *posledni = prvni + n - 1;
	while (prvni <= posledni) {
		cin >> *prvni;
		prvni++;
	}
	prvni = vstup;
	while (*prvni != 1 && prvni < posledni) {
		prvni++;
	}
	if (*prvni != 1) {
		cout << -1;
		return 0;
	}
	while (*posledni != e && posledni > prvni) {
		posledni--;
	}
	if (*posledni != e) {
		cout << -1;
		return 0;
	}
	int *koncePodmnozin = new int[posledni - prvni + 2];
	int *pocetPrvku = new int;
	*pocetPrvku = 1;
	*(koncePodmnozin + 1) = 1;
	while (prvni < posledni) {
		prvni++;
		ProvedPorovnani(pocetPrvku, *prvni, koncePodmnozin);
	}
	cout << *pocetPrvku;
	delete[] vstup;
	delete[] koncePodmnozin;
	delete pocetPrvku;
	return 0;
}