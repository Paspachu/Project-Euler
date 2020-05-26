#include <iostream>
#include <vector>
using namespace std;

vector<long long> triangle, pentagon, hexagon;


void create_triangles(int n) {
    for (long long i = 1; i <= n; i++) {
        triangle.push_back(i*(i+1)/2);
    }
}


void create_pentagons(int n) {
    for (long long i = 1; i <= n; i++) {
        pentagon.push_back(i*(3*i-1)/2);
    }
}


void create_hexagons(int n) {
    for (long long i = 1; i <= n; i++) {
        hexagon.push_back(i*(2*i-1));
    }
}


bool check_pentagon(long long p) {
    int i = 0;

    while (pentagon[i] <= p) {
        if (pentagon[i] == p) {
            return true;
        }

        i++;
    }

    return false;
}


bool check_hexagon(long long h) {
    int i = 0;

    while (hexagon[i] <= h) {
        if (hexagon[i] == h) {
            return true;
        }

        i++;
    }

    return false;
}


int solve(int n) {
    create_triangles(n);
    create_pentagons(n);
    create_hexagons(n);


    int count = 0;
    for (int i = 0; i < triangle.size(); i++) {
        if (check_pentagon(triangle[i]) && check_hexagon(triangle[i])) {
            cout << triangle[i] << endl;
            count++;
        }

        if (count > 2) {
            break;
        }
    }

    return 0;
}


int main() {
    solve(10000000);

    return 0;
}