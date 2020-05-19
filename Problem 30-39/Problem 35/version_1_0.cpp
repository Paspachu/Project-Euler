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


bool check_prime(int p) {
    if (p == 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


void vector_print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
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


vector<int> move_left_once(vector<int> v) {
    int temp = v.back();

    for (int i = v.size()-1; i > 0; i--) {
        v[i] = v[i-1];
    }

    v[0] = temp;

    return v;
}


vector<int> circular_numbers(int n) {
    vector<int> numbers;
    vector<int> v = int_to_vector(n);
    vector<int> t = move_left_once(v);

    numbers.push_back(n);

    while (t != v) {
        if (!check_contains(numbers, vector_to_int(t))) {
            numbers.push_back(vector_to_int(t));
        }
        t = move_left_once(t);
    }

    return numbers;
}


bool check_circular_prime(int n) {
    vector<int> c = circular_numbers(n);

    for (int i = 0; i < c.size(); i++) {
        if(!check_prime(c[i])) {
            return false;
        }
    }

    return true;
}


int solve(int n) {
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (!check_prime(i)) {
            continue;
        } else {
            if (check_circular_prime(i)) {
                count++;
            }
        }
    }

    return count;
}


int main() {
    cout << solve(1000000) << endl;

    return 0;
}