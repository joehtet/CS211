#include <iostream>
using namespace std;

void print(int q[]) {
    int i,j,k,l;

    typedef char box[5][7];
    box bb, wb, *board[8][8];

    // fill bb and wb
    for(i=0; i<5; i++) {
        for(j=0; j<7; j++) {
            bb[i][j] = 'X'; 
            wb[i][j] = ' ';
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
            cout << " " << char(179);
            for(j=0; j<8; j++) {
                for(l=0; l<7;  l++) {
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << char(179) << endl;
        }
    }

    // print lower border
    cout << "   ";
    for(i=0; i<7*8; i++) {
        cout << char(196);
    }

    cout << endl;   
}

int main() {
    int q[8] = {  0,1,2,3,4,5,6,7  }; 


    print(q);

    return 0;
}