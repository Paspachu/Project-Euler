#include <iostream>
#include <vector>
#include <algorithm>
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


vector<int> int_to_vector(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    return v;
}


int solve() {
    vector<int> a, b, c;

    for (int i = 1000; i < 3340; i++) {
        if (check_prime(i) && check_prime(i+3330) && check_prime(i+6660)) {
            a = int_to_vector(i);
            b = int_to_vector(i+3330);
            c = int_to_vector(i+6660);

            if (is_permutation(a.begin(), a.end(), b.begin()) && is_permutation(b.begin(), b.end(), c.begin())) {
                cout << i << i+3330 << i+6660 << endl;
            }
        }
    }

    return 0;
}


int main() {
    solve();

    return 0;
}