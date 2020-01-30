#include "stdio.h"
#include "stdlib.h"

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

int main() {
	int n, e;
	scanf("%d %d", &n, &e);
	int *vstup = (int*)malloc(sizeof(int)*n);
	int *prvni = vstup;
	int *posledni = prvni + n - 1;
	while (prvni <= posledni) {
		scanf("%d", prvni);
		prvni++;
	}
	prvni = vstup;
	while (*prvni != 1 && prvni < posledni) {
		prvni++;
	}
	if (*prvni != 1) {
		printf("-1");
		return 0;
	}
	while (*posledni != e && posledni > prvni) {
		posledni--;
	}
	if (*posledni != e) {
		printf("-1");
		return 0;
	}
	int *koncePodmnozin = (int*)malloc(sizeof(int)*(posledni - prvni + 2));
	int *pocetPrvku = (int*)malloc(sizeof(int));
	*pocetPrvku = 1;
	*(koncePodmnozin + 1) = 1;
	while (prvni < posledni) {
		prvni++;
		ProvedPorovnani(pocetPrvku, *prvni, koncePodmnozin);
	}
	printf("%d", *pocetPrvku);
	free(vstup);
	free(koncePodmnozin);
	free(pocetPrvku);
	return 0;
}