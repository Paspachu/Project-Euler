#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17};


long long vector_to_long_long(vector<int> v) {
    long long n = 0;
    long long m = 1;

    for (int i = v.size()-1; i >= 0; i--) {
        n += (v[i] * m);
        m *= 10;
    }

    return n;
}


bool check_property(vector<int> v) {
    for (int i = 1; i <= 7; i++) {
        vector<int> temp(v.begin()+i, v.begin()+i+3);
        long long t = vector_to_long_long(temp);

        if (t % primes[i-1] != 0) {
            return false;
        }
    }

    return true;
}


long long solve() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long answer = 0;

    while (next_permutation(v.begin(), v.end())) {
        if (check_property(v)) {
            answer += vector_to_long_long(v);
        }
    }

    return answer;
}


int main() {
    cout << solve() << endl;

    return 0;
}