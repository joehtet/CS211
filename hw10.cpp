// Htet, Joseph
// CS211 Section 22D Homework 10

/*
    Integration
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double line(double x) {
    return x;
}

double square(double x) {
    return x*x;
}

double cube(double x) {
    return x*x*x;
}

typedef double (*FUNC)(double);
double integrate(FUNC f, int a, int b) {
    double sum = 0;
    double delta = .0001;
    double x = a;
    
    // make delta rectangle
    while(x<b) {
        sum += f(x)*delta;
        x+=delta;
    }

    return sum;
}


int main() {

    cout<< "The integral of f(x)=x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl;
    cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
    cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;

    return 0;
}