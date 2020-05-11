#include <iostream>
#include <vector>
using namespace std;

vector<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


long long factorial(int n) {
    long long products = 1;

    for (int i = 2; i <= n; i++) {
        products *= i;
    }

    return products;
}


void solve(int p) {
    int i = 9;
    int f, u;

    f = factorial(i);
    while (p != 0) {
        u = p/f;
        
        if (p % f == 0) {
            u = u-1;
        }

        cout << l[u];

        l.erase(l.begin()+u);
        p = p % f;
        i--;
        f = factorial(i);
    }

    for (int j = l.size()-1; j >= 0; j--) {
        cout << l[j];
    }

    cout << endl;
}


int main() {
    solve(1000000);

    return 0;
}