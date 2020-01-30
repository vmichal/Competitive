//https://projecteuler.net/problem=15

/*Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?

*/

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

#define X 21
#define Y 21

long long body[X][Y];

void InicializujPole() {
	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			body[x][y] = -1;
		}
	}
}


int main() {

	InicializujPole();
	for (int i = 0; i < X; i++) 
		body[i][0] = 1;
	for (int i = 1; i < Y; i++) 
		body[0][i] = 1;
	for (int x = 1; x < X; x++) 
		for (int y = 1; y < Y; y++) 
			body[x][y] = body[x - 1][y] + body[x][y - 1];

	cout << body[X - 1][Y - 1] << endl;
    return 0;
}