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
    int sum = 0;
    vector<int> the_number = {2};

    for (int i = 2; i <= n; i++) {
        the_number = vector_addition(the_number, the_number);
    }
    
    sum = vector_sum(the_number);

    return sum;
}


int main() {
    cout << solve(1000) << endl;

    return 0;
}