// Htet, Joseph
// CS211 Section 22D Homework 5

/*
    Complete the 8 queens 1 dimensional array program with 
    backtracking that we worked on in class without GOTOs.
Link: 
    http://venus.cs.qc.cuny.edu/~cli/211/lab_php/lab.php?name=without_goto_outline
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

void print(int q[8], int col) {
    int board[8][8] = {0};

    // place 1's on board
    for(int i=0; i<8; i++) {
        board[q[i]][i] = 1;
    }

    cout << "  Solution #" << col << endl;
    /*
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cout << " " << board[i][j];
        }
        cout << endl;
    }
    */

    for(int i=0; i<8; i++) {
        cout << q[i] << endl;
    }
    cout << "----------------" << endl;
}

bool ok(int q[], int col) {
    for (int i = 0; i < col; i++) {             
        if (q[i]==q[col] || (col-i)==abs(q[col]-q[i])) {
            return true;
        }
    }

    return false;
}

void backtrack(int &col) {
    col--;
    if(col==-1) {
        exit(0);
    }
    
}

int main(){

    /*board setup */

    int q[8];
    int c=1;
    int counter=0;

    q[0] = 0;


    bool from_backtrack=false;

    while(true){  //loop for finding all solutions
        while(c<8){//loop for next col:
            if(!from_backtrack) {//if from backtrack go to next row.

                /*column section*/
                q[c] = -1;
                from_backtrack = true;
            }

            from_backtrack=false;
            while(q[c]<8){ //loop for next row:

                /*row section*/
                q[c]++;

                if(q[c]==8) { 
                    from_backtrack=true;
                    backtrack(c);
                    break;
                }

                if(ok(q,c)) {
                    from_backtrack = false;
                    c++;
                    break;
                }

                from_backtrack=true;
                backtrack(c); //backtrack always follows flag.
            }
        }
        counter++;
        print(q,counter) ;/*print section*/
        from_backtrack=true;
        backtrack(c); //after print go to backtrack.
    }

    return 0;
}
