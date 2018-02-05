

#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n);

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
