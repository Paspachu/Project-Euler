#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void vector_print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}


bool check_palindrome(vector<int> v) {
    vector<int> r = v;
    reverse(r.begin(), r.end());

    if (v == r) {
        return true;
    }

    return false;
}


vector<int> int_to_vector(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    return v;
}


vector<int> vector_addition(vector<int> u, vector<int> v) {
    vector<int> sum;
    int up = 0;

    for (int i = 0; i < u.size(); i++) {
        if (i < v.size()) {
            sum.push_back((u[i] + v[i] + up) % 10);
            up = (u[i] + v[i] + up) / 10;
        } else {
            sum.push_back((u[i] + up) % 10);
            up = (u[i] + up) / 10;
        }
        
        if (i == (u.size()-1) && up > 0) {
            sum.push_back(up);
        }
    }

    return sum;
}


vector<int> vector_reverse(vector<int> v) {
    reverse(v.begin(), v.end());

    return v;
}


bool check_lychrel(int n) {
    vector<int> v = int_to_vector(n);
    vector<int> r;

    for (int i = 0; i < 50; i++) {
        r = vector_reverse(v);
        v = vector_addition(v, r);

        if (check_palindrome(v)) {
            return false;
        }
    }

    return true;
}


int solve(int n) {
    int count = 0;

    for (int i = 10; i < n; i++) {
        if (check_lychrel(i)) {
            count++;
        }
    }

    return count;
}


int main() {
    cout << solve(10000) << endl;

    return 0;
}