// Logan Mayes
// lbm7fq@mail.umkc.edu
// 201R
// 05/09/2020

#include "Header.h"
#include <iostream>

using namespace std;


int main() 
{
	int tokens = 13, turns, required;
	char userInput; 
	
	do {
		
		cout << "Please enter the number of tokens you want to reach: ";
		cin >> required;
		
		cout << "How many turns would you like to take: ";
		cin >> turns;
		cout << "Searching for the solution within " << turns << " turn(s)..." << endl;
		steps(tokens, required, turns);
		
		
		cout << "\nWould you like to play again? [Y/N]: "; 
		cin >> userInput;
	} 
	
	while (userInput == 'Y' || userInput == 'y');
	cout << "Thanks for playing!" << endl; 

	return 0; 
}

