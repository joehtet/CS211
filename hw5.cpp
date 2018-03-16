// Htet, Joseph 
// CS211 Section 22D Homework 5

/* 
    Complete the 8 queens 1 dimensional array program without gotos
*/


#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void print(int q[]) {
    int board[8][8] = {0};

    // place 1's on board
    for(int i=0; i<8; i++) {
        board[q[i]][i] = 1;
    }
 
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
    cout << "----------------" << endl;

}

void backtrack(int &c) {
    c--;
    if(c==-1) { 
        exit(1); 
    }
}

bool ok(int q[], int c) {
    for(int i = 0; i < c; i++) {
        if(q[i] == q[c] || (c-i) == abs(q[c] - q[i])) {
            return false;
        }
    }
    return true;
}

int main() {

    // initialize    
    int c = 0;
    int row=0;
    int q[8];
    q[0] = 0;
    bool fromBacktrack = false;

    int counter = 1;

    while(true) {
    // loop through columns
        while(c!=8) {

            if(fromBacktrack) {
                row = q[c]+1;
                fromBacktrack = false;
            }
            else { row=0; }
            
            for(q[c]=row; q[c]!=8; ++q[c]) {
                if(ok(q, c)) {
                    break;
                }
            }

            if(q[c] >= 8) {
                backtrack(c);
                fromBacktrack = true;
            }

            else { c++; }

        }

        cout << "   Solution #" << counter << endl;
        print(q);
        counter++;
        backtrack(c);
        fromBacktrack = true;
    }

    return 0;
}

