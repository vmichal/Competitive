// Koktavý kevin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main() {
	char znak = '\0', minulyZnak = '\0';
	while (znak != EOF) {
		while ((znak = getchar()) == minulyZnak);
		if (znak != minulyZnak)
			std::cout << znak;
		minulyZnak = znak;		
	}	
    return 0;
}

