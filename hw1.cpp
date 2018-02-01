// Htet, Joseph
// CS211 Section 22D Homework 1

// Write a program to find and print the first perfect square(i*i) whose last two digits are both odd.

#include <iostream>
using namespace std;

// this function checks if the last two digits of num are both odd
bool isOdd(int num) {

	int ones_digit = num%10;
	int tens_digit = (num/10)%10;

	return (ones_digit%2!=0 && tens_digit%2!=0);
}	

int main() {

	int perfectSquare;
	int i = 4; // start i from 4 because 3*3=9 is one digit. i=4 and higher is at least two digits 	
	
	while(true) {
		perfectSquare = i*i;	

		if(isOdd(perfectSquare)) {
			cout << perfectSquare;
			break;
		};

		i++;
	}
	
	return 0;
}
