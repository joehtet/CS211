// Htet, Joseph
// CS211 Section 22D Homework 1

// Write a program to find and print the first perfect square(i*i) whose last two digits are both odd.

#include <iostream>
using namespace std;

// checks if the last two digits of num are both odd
bool isOdd(int num) {

	int ones_digit = num%10;
	int tens_digit = (num/10)%10;

	return (ones_digit%2!=0 && tens_digit%2!=0);
}	

int main() {

	int perfectSquare = 0;
	int n = 200;
	
	for(int i=4; i<n; i++) { 
		// start i from 4 because 3*3=9 is one digit. i=4 and higher is at least two digits 	

		perfectSquare = i*i;	
//cout << (perfectSquare/10)%10 << perfectSquare%10 << " ";

		if(isOdd(perfectSquare)) {
			// the solution is found and program is terminated
			cout << perfectSquare;
			return 0;
		}
	}
	
	cout << "No solution" ;

	return 0;
}

// After running the program using a sufficiently large n and looking at the last two digits of the results (line 27), I noticed a repeating pattern.
// The pattern  is 00,01,04,09,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,00,41,84,29,76,25,76,29,84,41,00,61,24,89,56,25,96,69,44,21,00,81,64,49,36,25,16,09,04,01
// Since the pattern repeats and there is no odd number, there is no solution. 
