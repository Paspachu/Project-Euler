#include <iostream>
using namespace std;

int solve(double n) {
    for (int a = 1; a < n/3; a++) {
        for (int b = a+1; b < (n-a)/2; b++) {
            int c = n-a-b;
            if ((a*a + b*b) == c*c) {
                return a*b*c;
            }
        }
    }

    return 0;
}

int main() {
    cout << solve(1000) << endl;

    return 0;
}