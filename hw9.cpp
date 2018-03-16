// Htet, Joseph
// CS211 Section 22D Homework 4

/*
    Fancy printing for 1 dimensional queens problem.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

void print(int q[]) {
    int i,j,k,l;

    typedef char box[5][7];
    box bb, wb, bq, wq, *board[8][8];

    // fill boxes with appropriate chars
    for(i=0; i<5; i++) {
        for(j=0; j<7; j++) {
            bb[i][j] = 'X'; 
            wb[i][j] = ' ';

        
            // fill queens
            if(i==1 && j%2!=0) {
                bq[i][j] = 'X';
                wq[i][j] = ' ';
            }
            else if(i==2 || i==3) {
                bq[i][j] = 'X';
                bq[i][0] = ' ';
                bq[i][6] = ' ';

                wq[i][j] = ' ';
                wq[i][0] = 'X';
                wq[i][6] = 'X';


            }
            else {
                bq[i][j] = ' ';
                wq[i][j] = 'X';
            }
        }
    }

    

    // fill board with boxes
    for(i=0; i<8; i++) {
        for(j=0; j<8; j++) {
            if((i+j)%2==0) {
                board[i][j] = &wb;
            }
            else {
                board[i][j] = &bb;
            }
        }
    }

    // print upper border
    cout << "  " ;
    for(i=0; i<7*8;i++) {
        cout << '_';
    }
    cout << endl;

    // print board
    for(i=0; i<8; i++) {
        for(k=0; k<5; k++) {
            cout << " " << "|"; //5char(179);
            for(j=0; j<8; j++) {
                for(l=0; l<7;  l++) {
                    // if the current position on board (i,j) is also in q[i],
                    if(j==q[i]) {
                        // replace box with appropriate queen in board array
                        if((i+j)%2==0) {
                            board[i][j] = &bq;
                        }
                        else {
                            board[i][j] = &wq;
                        }
                    }

                    // draw board
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << "|" <<endl; //char(179) << endl;
        }
    }

    // print lower border
    cout << "   ";
    for(i=0; i<7*8; i++) {
        cout << "-"; //char(196);
    }

    cout << endl;   
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

