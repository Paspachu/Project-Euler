#include <iostream>
#include <vector>
#include<math.h>
using namespace std;


bool check_prime(int p) {
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            return false;
        }
    }

    return true;
}


bool check_contains(vector<int> v, int n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return true;
        }
    }

    return false;
}


void vector_print(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}


int array_to_int(int *v, int s) {
    int n = 0;
    int m = 1;

    for (int i = 0; i < s; i++) {
        n += (v[i] * m);
        m *= 10;
    }

    return n;
}


int number_of_primes(vector<int> v) {
    int count = 0;

    for (int i = 0; i < v.size(); i++) {
        if (check_prime(v[i])) {
            count++;
        }
    }

    return count;
}


vector<vector<int>> subsets(int n, int r) {
    vector<int> v;

    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    vector<vector<int>> s;
    vector<int> t;

    for (int i = 1; i < pow(2, n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                t.push_back(v[j]);
            }
        }
        
        if (t.size() == r) {
            s.push_back(t);
        }

        t.clear();
    }

    return s;
}


vector<int> possibles(int l, vector<int> p, int n) {
    vector<int> numbers;
    vector<int> q;
    int t[l];

    for (int i = 0; i < l; i++) {
        if (!check_contains(p, i)) {
            q.push_back(i);
        }
    }

    for (int i = 0; i < q.size(); i++) {
        t[q[i]] = n % 10;
        n = n / 10;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < p.size(); j++) {
            t[p[j]] = i;
        }

        if (t[l-1] == 0) {
            continue;
        }

        numbers.push_back(array_to_int(t, l));
    }

    return numbers;
}


vector<int> solve(int n) {
    vector<int> t;
    vector<vector<int>> s;
    int d = 2;

    while (true) {
        for (int b = 1; b < d; b++) {
            s = subsets(d-1, b);

            for (int i = 0; i < s.size(); i++) {
                for (int j = pow(10, d-b-1); j < pow(10, d-b); j++) {
                    t = possibles(d, s[i], j);

                    //vector_print(t);

                    if (number_of_primes(t) == n) {
                        return t;
                    }
                }
            }
        }

        d++;
    }

    return {};
}


int main() {
    vector<int> v = solve(8);
    vector_print(v);

    return 0;
}