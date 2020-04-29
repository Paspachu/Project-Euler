#include <iostream>
#include <vector>
using namespace std;

int m = 50;


vector<int> initialize_vector(vector<int> v) {
    for (int i = 0; i < m; i++) {
        v.push_back(0);
    }

    return v;
}


//This function assumes that the size of vector u is greater than or equal to that of vector v.
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


vector<int> solve(int n) {
    vector<int> sum;
    vector<int> u;
    sum = initialize_vector(sum);
    char c;

    for (int i = 0; i < n; i++) {
        cin.get(c);
        while ((int)c-48 >= 0) {
            u.insert(u.begin(), (int)c-48);
            cin.get(c);
        }
        sum = vector_addition(sum, u);
        u.clear();
    }

    return sum;
}


int main() {
    vector<int> answer;

    answer = solve(100);
    cout << endl << "The answer is:" << endl;
    vector_print(answer);

    return 0;
}