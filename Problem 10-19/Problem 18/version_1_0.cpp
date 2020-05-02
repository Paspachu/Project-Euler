#include <iostream>
#include <vector>
using namespace std;

int s = 15;
vector<vector<int>> numbers;


 void read_input() {
    int x;
    vector<int> t;

    for (int i = 0; i < s; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> x;
            t.push_back(x);
        }
        numbers.push_back(t);
        t.clear();
    }
}


int vector_print_2d(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}


int solve() {
    int answer = 0;

    for (int i = s-2; i >= 0; i--) {
        for (int j = 0; j < numbers[i].size(); j++) {
            if (numbers[i+1][j] >= numbers[i+1][j+1]) {
                numbers[i][j] += numbers[i+1][j];
            } else {
                numbers[i][j] += numbers[i+1][j+1];
            }
        }
        numbers.erase(numbers.end());
        vector_print_2d(numbers);
    }

    return answer;
}


int main() {
    read_input();
    cout << endl;
    solve();

    return 0;
}