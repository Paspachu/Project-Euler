#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


bool check_contains(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return true;
        }
    }

    return false;
}


int factors(vector<int> f, int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (!check_contains(f, i)) {
                f.push_back(i);
            }
            
            return factors(f, n/i);
        }
    }

    if (!check_contains(f, n)) {
        f.push_back(n);
    }

    return f.size();
}


int solve(int n) {
    int flag = 0;
    int i = 2;
    vector<int> t;

    while (true) {
        for (int j = 0; j < n; j++) {
            if (factors(t, i+j) != n) {
                flag = 1;
            }
        }

        if (flag == 0) {
            return i;
        }

        flag = 0;
        i++;
    }

    return 0;
}


int main() {
    cout << solve(4) << endl;

    return 0;
}