#include <iostream>
#include "vector_int.h"
using namespace std;


vector<int> root_two_denom(int n) {
    vector<int> d = {2};
    vector<int> p = {1};
    vector<int> two = {2};
    vector<int> temp;

    for (int i = 1; i < n; i++) {
        temp = d;
        d = d*two + p;
        p = temp;
    }

    return d;
}


vector<int> slice(vector<int> v) {
    vector<int> u(v.end()-4, v.end());

    return u;
}


int solve(int n) {
    int count = 0;
    vector<int> u, v;
    vector<int> s = {2, 7, 0, 7};

    for (int i = 1; i <= n; i++) {
        u = root_two_denom(i);
        
        if (u.size() < 4) {
            v = u;

            while(v.size() < 4) {
                v.insert(v.begin(), 0);
            }
        } else {
            v = slice(u);
        }

        if (v > s) {
            count++;
        }
    }

    return count;
}


int main() {
    cout << solve(1000) << endl;

    return 0;
}