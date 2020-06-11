#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<vector<int>> taken;
vector<int> counts;


vector<int> long_long_to_vector(long long n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    return v;
}


long long vector_to_long_long(vector<int> v) {
    long long n = 0;
    long long m = 1;

    for (int i = 0; i < v.size(); i++) {
        n += (v[i] * m);
        m *= 10;
    }

    return n;
}


long long power(long long b, int p) {
    long long result = b;

    for (int i = 1; i < p; i++) {
        result *= b;
    }

    return result;
}


int update(vector<int> v) {
    for (int i = 0; i < taken.size(); i++) {
        if (v.size() == taken[i].size() && is_permutation(taken[i].begin(), taken[i].end(), v.begin())) {
            counts[i]++;
            return 1;
        }
    }

    taken.push_back(v);
    counts.push_back(1);

    return 0;
}


long long solve(int n) {
    long long i = 2;
    long long p;
    vector<int> t;

    while (true) {
        p = power(i, 3);
        t = long_long_to_vector(p);
        update(t);
        
        for (int j = 0; j < counts.size(); j++) {
            if (counts[j] == n) {
                return vector_to_long_long(taken[j]);
            }
        }

        i++;
    }

    return 0;
}


int main() {
    cout << solve(5) << endl;

    return 0;
}