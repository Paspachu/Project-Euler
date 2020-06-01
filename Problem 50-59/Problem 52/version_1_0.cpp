#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> int_to_vector(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    return v;
}


int solve(int n) {
    vector<int> b, t;
    int i = 11;
    int flag;

    while (true) {
        b = int_to_vector(i);
        flag = 0;

        for (int j = 2; j <= n; j++) {
            t = int_to_vector(i*j);
            if (t.size() != b.size() || !is_permutation(b.begin(), b.end(), t.begin())) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            return i;
        }

        i++;
    }

    return 0;
}


int main() {
    cout << solve(6) << endl;

    return 0;
}