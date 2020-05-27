#include <iostream>
#include <vector>
using namespace std;


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


vector<int> vector_cut_last_ten(vector<int> v) {
    vector<int> u;

    if (v.size() < 10) {
        return v;
    }

    for (int i = 0; i < 10; i++) {
        u.push_back(v[i]);
    }

    return u;
}
 

int vector_print(vector<int> v) {
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;

    return 0;
}


vector<int> int_to_vector(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    return v;
}


int solve(int n) {
    vector<int> sum;
    vector<int> t = {1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            t = vector_multiplication(t, int_to_vector(i));
            t = vector_cut_last_ten(t);
        }
        sum = vector_addition(t, sum);
        sum = vector_cut_last_ten(sum);
        t = {1};
    }

    vector_print(sum);

    return 0;
}


int main() {
    solve(1000);

    return 0;
}