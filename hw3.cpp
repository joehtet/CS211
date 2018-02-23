// Htet, Joseph
// CS211 Section 22D Homework 3

/*
    Complete the 8 queens 2 dimensional array program with 
    backtracking that we worked on in class.
Link: 
    venus.cs.qc.cuny.edu/~cli/211/lab_php/lab.php?name=lab4
*/

#include <iostream>
using namespace std;

void print(int b[8][8], int c) {
    
    cout << "  Solution #" << c << endl;

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cout << " " << b[i][j];
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

int main() {
    
    int c=0, r=0, counter=0;
    int b[8][8] = {0};

    b[0][0] = 1;


next_col: 
    c++;

    // set a wall to stop c++
    if(c==8) { 
        goto print; 
    }

    r = -1;


next_row: 
    r++;

    if(r==8) { 
        goto backtrack; 
    }

    // row test
    for(int i=0; i<c; i++) {
        if(b[r][i]==1) {
            goto next_row;
        }
    }

    // up diag test
    for(int i=1; (r-i)>=0 && (c-i)>=0; i++) {
        if(b[r-i][c-i]==1) {
            goto next_row;
        }
    }

    // down diag test
    for(int i=1; (r+i)<8 && (c-i)>=0; i++) {
        if(b[r+i][c-i]==1) {
            goto next_row;
        }
    }


    b[r][c] = 1;
    goto next_col;


backtrack: 
    c--;
    if(c==-1) { return 0; }

    for(int i=0; i<8; i++) {
        if(b[i][c]==1) {
            r = i;
            break;
        }
        else {r=0;}
    }

    b[r][c] = 0;
    goto next_row;


print:
    counter++;
    print(b, counter);
    goto backtrack;
}
