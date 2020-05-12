#include <iostream>
#include <vector>
using namespace std;


int vector_print(vector<int> v) {
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;

    return 0;
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


int solve(int d) {
    vector<int> first = {1};
    vector<int> second = {1};
    int index = 3;

    vector<int> temp;
    while (second.size() < d) {
        temp = second;
        second = vector_addition(second, first);
        first = temp;

        index++;
    }

    index--;

    return index;
}


int main(){
    cout << solve(1000) << endl;

    return 0;
}