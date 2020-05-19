#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


void vector_print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }

    cout << endl;
}


bool check_prime(int p) {
    if (p <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(p); i++) {
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


vector<int> int_to_vector(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    return v;
}


bool left_to_right(int p) {
    vector<int> q = int_to_vector(p);

    for (int i = 1; i <= q.size(); i++) {
        vector<int> t(q.begin(), q.begin() + i);
        if (!check_prime(vector_to_int(t))) {
            return false;
        }
    }

    return true;
}


bool right_to_left(int p) {
    vector<int> q = int_to_vector(p);

    for (int i = 1; i <= q.size(); i++) {
        vector<int> t(q.end() - i, q.end());
        if (!check_prime(vector_to_int(t))) {
            return false;
        }
    }

    return true;
}


int solve() {
    int count = 0;
    int i = 20;
    int sum = 0;

    while (count < 11) {
        if (left_to_right(i) && right_to_left(i)) {
            sum += i;
            count++;
        }
        i++;
    }

    return sum;
}


int main() {
    cout << solve() << endl;

    return 0;
}