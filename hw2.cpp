// Htet, Joseph
// CS211 Section 22D Homework 2

#include <iostream>
using namespace std;

static bool isEqual(int a1[], int a2[], int n) {

    for(int i=0; i<n; i++) {
//        cout << a1[i] << " " << a2[i] << endl;
        if(a1[i]!=a2[i]) {
            return false;
        }
    }

    return true;
}


bool equivalent(int a[], int b[], int n) {
    int tempArray[n];

    for(int i=0; i<n; i++) {

        for(int j=0; j<n; j++) {
            tempArray[j] = b[(i+j)%n];
        }

        if(isEqual(a, tempArray, n)) {
            return true;    
        };

    }

    return false;    
};

int main() {
   cout << boolalpha; // to show boolean value as "true" or "false"

   int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};
   cout << equivalent(a1, a2, 5) << endl; // true

   int a3[3] = {1, 2, 3};
   int a4[3] = {2, 3, 3};
   cout << equivalent(a3, a4, 3) << endl; // false

   int a5[4] = {1, 1, 0, 1};
   int a6[4] = {1, 0, 1, 1};
   cout << equivalent(a5, a6, 4) << endl; // true

   int a7[4] = {5, 6, 7, 8};
   int a8[4] = {5, 6, 7, 8};
   cout << equivalent(a7, a8, 4) << endl; // true

   return 0;
}
