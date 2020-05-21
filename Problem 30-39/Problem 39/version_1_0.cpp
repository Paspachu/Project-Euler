#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> triangles(int p) {
    vector<vector<int>> possible;
    vector<int> temp;

    for (int i = p/2; i >= p/3; i--) {
        for (int j = i; j >= (p-i)/2; j--) {
            int k = p-i-j;
            
            if(k > j) {
                continue;
            }

            if (j+k > i) {
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(k);
                possible.push_back(temp);
                temp.clear();
            }
        }
    }

    return possible;
}


int right_triangles(int p) {
    int count = 0;
    vector<vector<int>> t = triangles(p);
    int a, b, c;

    for (int i = 0; i < t.size(); i++) {
        a = t[i][2];
        b = t[i][1];
        c = t[i][0];

        if (a*a + b*b == c*c) {
            count++;
        }
    }

    return count;
}


int solve(int n) {
    int answer = 0;
    int highest = 0;
    int t;

    for (int p = 12; p <= n; p++) {
        t = right_triangles(p);
        if (t >= highest) {
            answer = p;
            highest = t;
        }
    }

    return answer;
}


int main() {
    cout << solve(1000) << endl;

    return 0;
}