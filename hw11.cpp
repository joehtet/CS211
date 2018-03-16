
// Htet, Joseph
// CS211 Section 22D Homework 9

/*
    Number of solutions to the n-queen problem.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void backtrack(int &c) {
    c--;
}

bool ok(int q[], int c) {
    for(int i = 0; i < c; i++) {
        if(q[i] == q[c] || (c-i) == abs(q[c] - q[i])) {
            return false;
        }
    }
    return true;
}

int getNumSolutions(int n) {
    int *q = new int[n];
    int counter = 0; 

    // initialize    
    int c = 0;
    int row=0;
    q[0] = 0;
    bool fromBacktrack = false;


    while(true) {
    // loop through columns
        while(c!=n) {

            if(fromBacktrack) {
                row = q[c]+1;
                fromBacktrack = false;
            }
            else { row=0; }
            
            for(q[c]=row; q[c]!=n; ++q[c]) {
                if(ok(q, c)) {
                    break;
                }
            }

            if(q[c] >= n) {
                backtrack(c);
                if(c==-1) { 
                    delete [] q;
                    return counter;
                }
                fromBacktrack = true;
            }

            else { c++; }

        }

        counter++;
        backtrack(c);
        if(c==-1) { 
            delete [] q;
            return counter;
        }
        fromBacktrack = true;
    }
}


int main() {
    
    int n;
    cout << "Enter number of queens: " << endl;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cout << i << ". There are " <<    getNumSolutions(i) << " solutions to the " << i << " queens problem." << endl;;
    }

    return 0;
}
