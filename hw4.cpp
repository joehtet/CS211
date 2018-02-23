// Htet, Joseph
// CS211 Section 22D Homework 4

/*
    Complete the 8 queens 1 dimensional array program with 
    backtracking that we worked on in class.
Link: 
    venus.cs.qc.cuny.edu/~cli/211/lab_php/lab.php?name=lab5
*/

#include <iostream>
#include <cmath>
using namespace std;

void print(int q[8], int c) {
    int board[8][8] = {0};

    // place 1's on board
    for(int i=0; i<8; i++) {
        board[q[i]][i] = 1;
    }

    cout << "  Solution #" << c << endl;
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

int main() {
    
    int q[8];
    int c=0;
    int counter=0;

    q[0] = 0;


next_col: 
    c++;

    // set a wall to stop c++
    if(c==8) { 
        goto print; 
    }

    q[c] = -1;


next_row: 
    q[c]++;

    if(q[c]==8) { 
        goto backtrack; 
    }

   // tests
    for (int i = 0; i < c; i++) {             
        if (q[i]==q[c] || (c-i)==abs(q[c]-q[i])) {
            goto next_row; 
        }
    }
    goto next_col;


backtrack: 
    c--;
    if(c==-1) { return 0; }

    goto next_row;


print:
    counter++;
    print(q, counter);
    goto backtrack;
}
