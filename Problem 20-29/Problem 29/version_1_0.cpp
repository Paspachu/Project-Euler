#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> distinct;


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


vector<int> vector_multiplication(vector<int> u, vector<int> v) {
    vector<int> product;
    vector<int> temp;
    int up;

    for (int i = 0; i < v.size(); i++) {
        up = 0;

        for (int j = 0; j < i; j++) {
            temp.push_back(0);
        }

        for (int k = 0; k < u.size(); k++) {
            temp.push_back((u[k] * v[i] + up) % 10);
            up = (u[k] * v[i] + up) / 10;

            if (k == (u.size()-1) && up > 0) {
                temp.push_back(up);
            }
        }

        product = vector_addition(temp, product);
        temp.clear();
    }

    return product;
}


vector<int> vector_power(vector<int> v, int p) {
    vector<int> power = {1};

    for (int i = 0; i < p; i++) {
        power = vector_multiplication(power, v);
    }

    return power;
}


bool check_contains(vector<vector<int>> v, vector<int> n) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == n) {
            return true;
        }
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


void vector_print(vector<int> v) {
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }

    cout << endl;
}


int solve(int n) {
    vector<int> vec_t, vec_a;

    for (int a = 2; a <= n; a++) {
        for (int b = 2; b <= n; b++) {
            vec_a = int_to_vector(a);
            vec_t = vector_power(vec_a, b);
            
            if (!check_contains(distinct, vec_t)) {
                distinct.push_back(vec_t);
            }
        }
    }

    return distinct.size();
}


int main() {
    cout << solve(100) << endl;

    return 0;
}
