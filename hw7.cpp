// Htet, Joseph
// CS211 Section 22D Homework 7

/*
    Stable Marriage problem
*/

#include <iostream>
#include <cstdlib>


using namespace std;

void print(int q[]) {
    cout << "Man    Woman" << endl;

    for(int i=0; i<3; i++) {
        cout << i << "  " << "  " << q[i] << endl;
    }
}


void backtrack(int &c) {
    c--;
    if(c==-1) { 
        exit(1); 
    }
}

bool ok(int q[], int c) {
    int mp[3][3] = {
        0,2,1,
        0,2,1,
        1,2,0
    };

    int wp[3][3] = {
        2,1,0,
        0,1,2,
        2,0,1
    };

    for(int i=0; i<c; i++) {
        if( q[i] == q[c] ) { 
            return false;
        }

        // current man - new woman
        else if((mp[i][q[c]] < mp[i][q[i]]) && (wp[q[c]][i] < wp[q[c]][c])) {
            return false;
        }

        // new man(c) - current woman(q[i])
        else if((mp[c][q[i]] < mp[c][q[c]]) && (wp[q[i]][c] < wp[q[i]][i])) {
            return false;
        }

        else{}

    }
    return true;
}

int main() {

    // initialize    
    int c = 0;
    int row=0;
    int q[3];
    // q[0] = 0;
    bool fromBacktrack = false;

    int counter = 1;

    while(true) {
    // loop through columns
        while(c!=3) {

            if(fromBacktrack) {
                row = q[c]+1;
                fromBacktrack = false;
            }
            else { row=0; }
            
            for(q[c]=row; q[c]!=3; ++q[c]) {
                if(ok(q, c)) {
                    break;
                }
            }

            if(q[c] >= 3) {
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

