#include <iostream>
#include <vector>
using namespace std;

vector<int> pentagon;


void create_pentagons(int n) {
    for (int i = 1; i <= n; i++) {
        pentagon.push_back(i*(3*i-1) / 2);
    }
}


bool check_pentagon(int p) {
    int i = 0;

    while (pentagon[i] <= p) {
        if (pentagon[i] == p) {
            return true;
        }

        i++;
    }

    return false;
}


int solve() {
    int i = 1;
    int s, d;

    while (true) {
        for (int j = i-1; j >= 0; j--) {
            s = pentagon[i] + pentagon[j];
            d = pentagon[i] - pentagon[j];

            if (check_pentagon(s) && check_pentagon(d)) {
                return d;
            }
        }

        i++;
    }

    return 0;
}


int main() {
    create_pentagons(1000000);
    cout << solve() << endl;

    return 0;
}