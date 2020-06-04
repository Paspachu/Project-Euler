#include <iostream>
#include <vector>
using namespace std;


void vector_print(vector<int> v) {
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }

    cout << endl;
}


vector<int> int_to_vector(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    return v;
}


int vector_sum(vector<int> v) {
    int sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    return sum;
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
    vector<int> u = {1};

    for (int i = 1; i <= p; i++) {
        u = vector_multiplication(u, v);
    }

    return u;
}


int solve(int n) {
    int answer = 0;
    vector<int> t, s;

    for (int a = 1; a < n; a++) {
        t = int_to_vector(a);
        for (int b = 1; b < n; b++) {
            s = vector_power(t, b);
            
            if (vector_sum(s) > answer) {
                answer = vector_sum(s);
            }
        }
    }

    return answer;
}


int main() {
    cout << solve(100) << endl;

    return 0;
}