#include <iostream>
#include <vector>
using namespace std;

vector<int> vzero = {0};


void print(vector<int> v) {
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }

    cout << endl;
}


vector<int> int_to_vector(int n) {
    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    return v;
}


bool operator>(const vector<int> &u, const vector<int> &v) {
    if (u.size() > v.size()) {
        return true;
    } else if (u.size() < v.size()) {
        return false;
    } else {
        for (int i = u.size()-1; i >= 0; i--) {
            if (u[i] > v[i]) {
                return true;
            } else if (u[i] < v[i]) {
                return false;
            } else {
                continue;
            }
        }
    }

    return false;
}


bool operator>=(const vector<int> &u, const vector<int> &v) {
    if (u.size() > v.size()) {
        return true;
    } else if (u.size() < v.size()) {
        return false;
    } else {
        for (int i = u.size()-1; i >= 0; i--) {
            if (u[i] > v[i]) {
                return true;
            } else if (u[i] < v[i]) {
                return false;
            } else {
                continue;
            }
        }
    }

    return true;
}


bool operator<(const vector<int> &u, const vector<int> &v) {
    if (u.size() < v.size()) {
        return true;
    } else if (u.size() > v.size()) {
        return false;
    } else {
        for (int i = u.size()-1; i >= 0; i--) {
            if (u[i] < v[i]) {
                return true;
            } else if (u[i] > v[i]) {
                return false;
            } else {
                continue;
            }
        }
    }

    return false;
}


bool operator<=(const vector<int> &u, const vector<int> &v) {
    if (u.size() < v.size()) {
        return true;
    } else if (u.size() > v.size()) {
        return false;
    } else {
        for (int i = u.size()-1; i >= 0; i--) {
            if (u[i] < v[i]) {
                return true;
            } else if (u[i] > v[i]) {
                return false;
            } else {
                continue;
            }
        }
    }

    return true;
}


bool operator==(const vector<int> &u, const vector<int> &v) {
    if (u.size() != v.size()) {
        return false;
    }

    for (int i = 0; i < u.size(); i++) {
        if (u[i] != v[i]) {
            return false;
        }
    }

    return true;
}


vector<int> operator+(const vector<int> &u, const vector<int> &v) {
    vector<int> sum, p, q;
    int up = 0;

    if (u < v) {
        p = v;
        q = u;
    } else {
        p = u;
        q = v;
    }

    for (int i = 0; i < p.size(); i++) {
        if (i < q.size()) {
            sum.push_back((p[i] + q[i] + up) % 10);
            up = (p[i] + q[i] + up) / 10;
        } else {
            sum.push_back((p[i] + up) % 10);
            up = (p[i] + up) / 10;
        }
        
        if (i == (p.size()-1) && up > 0) {
            sum.push_back(up);
        }
    }

    return sum;
}


vector<int> operator*(const vector<int> &u, const vector<int> &v) {
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

        product = temp + product;
        temp.clear();
    }

    return product;
}


vector<int> operator-(const vector<int> &u,const vector<int> &v) {
    vector<int> diff, p, q;

    if (u < v) {
        p = v;
        q = u;
    } else if (u > v) {
        p = u;
        q = v;
    } else {
        return {0};
    }

    for (int i = 0; i < p.size(); i++) {
        if (i < q.size()) {
            if (p[i] - q[i] < 0) {
                diff.push_back(p[i] + 10 - q[i]);
                p[i+1]--;
            } else {
                diff.push_back(p[i] - q[i]);
            }
        } else {
            diff.push_back(p[i]);
        }
    }

    for (int i = diff.size()-1; i >= 0; i--) {
        if (diff[i] != 0) {
            break;
        }

        diff.pop_back();
    }

    return diff;
}


vector<int> operator/(const vector<int> &u, vector<int> &v) {
    vector<int> quotient, t, p;

    if (u < v) {
        return {0};
    } else if (u == v) {
        return {1};
    }

    for (int i = u.size()-1; i >= 0; i--) {
        if (p == vzero) {
            p.pop_back();
        }

        p.insert(p.begin(), u[i]);

        if (p < v && i != 0) {
            quotient.insert(quotient.begin(), 0);
            continue;
        }

        for (int j = 1; j <= 10; j++) {
            t = int_to_vector(j);
            t = v*t;

            if (t > p) {
                quotient.insert(quotient.begin(), j-1);   
                p = p + v - t;
                t.clear();
                break;
            }

            t.clear();
        }
    }

    for (int i = quotient.size()-1; i >= 0; i--) {
        if (quotient[i] != 0) {
            break;
        }

        quotient.pop_back();
    }

    return quotient;
}


vector<int> operator%(const vector<int> &u, vector<int> &v) {
    vector<int> remainder, q;

    if (u < v) {
        return u;
    } else if (u == v) {
        return {0};
    }

    q = u / v;
    remainder = u - v*q;

    return remainder;
}