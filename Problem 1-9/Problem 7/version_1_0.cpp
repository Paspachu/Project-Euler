#include <iostream>
#include <math.h>
using namespace std;

bool check_prime(int p) {
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


int solve(int n) {
    int the_prime = 1;
    int count = 0;

    while (count < n) {
        the_prime++;
        if (check_prime(the_prime) == true) {
            count++;
        }
    }

    return the_prime;
}


int main() {
    cout << solve(10001) << endl;

    return 0;
}