// Htet, Joseph
// CS211 Section 22D Homework 6

#include <iostream>
using namespace std;

void print(int q[]) {
    cout << "  " << q[0] << " " << q[1] << endl;
    cout << q[2] << " " << q[3] << " " << q[4] << " " << q[5] << endl;
    cout << "  " << q[6] << " " << q[7] << endl;
}

bool ok(int q[], int s, int c) { 
    int a[8][8] = 
    {
        {-1}, 
        {0,-1},
        {0,-1},
        {0,1,2,-1}, 
        {0,1,3,-1}, 
        {1,4,-1}, 
        {2,3,4,-1}, 
        {3,4,5,6,-1} 
    };

    // row test left side of q[c]
    for(int j=0; j<c; j++) {
        if(s==q[j]) {
            return false;
        }
    }

    // adjacency test
    int k=0;
    while(a[c][k]!=-1) {
        if((q[a[c][k]]+1 == s) || (q[a[c][k]]-1 == s)) {
            return false;
        }
        k++;
    }

    
    return true; 
}

void backtrack(int &c) {
    c--;
}

int main() {

    // q[] - board
    int c = 0;
    int q[8];
    
/*
     _____
   _|__|__|_
  |_|__|__|_|
    |__|__|

*/
    int from_backtrack = false;
    int valueFound;

    while(c<8) {
        valueFound = false;

        int s;
        if(from_backtrack) { 
            from_backtrack = false;
            s=q[c]+1; 
        }
        else{s=1;}
        while(s<9) {
            if(ok(q,s,c)) {
                valueFound = true;
                q[c] = s;
                break;
            }
            s++;
        }        

        if(!valueFound) {
            from_backtrack = true;
            backtrack(c);    
        }

        else {
            c++;
        }
    }
    print(q); 
}
