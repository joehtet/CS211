// Htet, Joseph
// CS211 Section 22D Homework 2

#include <iostream>
using namespace std;

int shiftArray(int arr[], int shift_value) {
    int shiftedArray[] = new int[size(arr)];

    for(int i=0; i<arr.length; i++) {
        shiftedArray[i] = 0;
    }

    return shiftedArray;
}

bool equivalent(int a[], int b[], int n) { 
    cout << 1%5 << 2%5 << 3%5 << 4%5 << 5%5;
    // 1. generate arrays of all possibilites 
    // then check if arrays are equal
    int shiftedArrays[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            shiftedArrays[i][j] = 0;
        }
    }


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


   return 0;
}
