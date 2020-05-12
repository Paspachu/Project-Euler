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


int vector_print(vector<int> v) {
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;

    return 0;
}


int vector_sum(vector<int> v) {
    int sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    
    return sum;
}


int solve(int n) {
    vector<int> answer = {1};
    vector<int> temp;
    int t;

    for (int i = 1; i <= n; i++) {
        t = i;
        while (t > 0) {
            temp.push_back(t % 10);
            t = t/ 10;
        }

        answer = vector_multiplication(temp, answer);
        temp.clear();
    }

    vector_print(answer);

    return vector_sum(answer);
}


int main() {
    cout << solve(100) << endl;

    return 0;
}