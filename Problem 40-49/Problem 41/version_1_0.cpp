#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


bool check_prime(long long p) {
    for (long long i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


int vector_to_int(vector<int> v) {
    int n = 0;
    int m = 1;

    for (int i = 0; i < v.size(); i++) {
        n += (v[i] * m);
        m *= 10;
    }

    return n;
}


long long solve() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    long long answer = 0;
    long long t;

    while (next_permutation(v.begin(), v.end())) {
        t = vector_to_int(v);
        if (t >= answer && check_prime(t)) {
            answer = t;
        }
    }

    return answer;
}


int main() {
    cout << solve() << endl;

    return 0;
}