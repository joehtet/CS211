#include <iostream>
using namespace std;


int getSolutions(int n) {
// Return number of solutions to the n queen problem.
    return 0;
}

int main() {
    
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        cout << i+1 << ". There are " <<    getSolutions(n) << " solutions to the " << n << " queens problem." << endl;;
    }
 

    return 0;
}
