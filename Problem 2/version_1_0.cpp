#include <iostream>
using namespace std;

int solve(int n) {
    int sum = 2;
    int i = 1;
    int j = 2;

    while(i + j < n) {
        int t = j;
        j = i+j;
        i = t;
        if (j % 2 == 0) {
            sum += j;
        }
    }

    return sum;
}

int main() {
    cout << solve(4000000) << endl;

    return 0;
}