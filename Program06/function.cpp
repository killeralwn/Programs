// Logan Mayes
// lbm7fq@mail.umkc.edu
// 201R
// 05/09/2020

#include "Header.h"
#include <iostream>

using namespace std;

void steps(int tokens, int required, int turns)
{
	if (turns == 0) {
		cout << "The solution could not be found within the given amount of rounds." << endl;
		return;
	}

	if (tokens == required) {
		cout << "Solution found with " << turns << " turn (s) remaining." << endl;
		return;
	}

	if (tokens % 2 == 1) {
		tokens += 25;
		cout << "Adding 25, you get " << tokens << " tokens." << endl;
	}

	else {
		tokens /= 2;
		cout << "Reducing by half, you get " << tokens << " tokens." << endl;
	}

	steps(tokens, required, turns - 1);
}