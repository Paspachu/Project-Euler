#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct real {
    int s;
    int r;
};

struct fraction {
    real n;
    real d;
};

struct list {
    int i;
    fraction f;
};


void real_print(real n) {
    if (n.s != 0) {
        cout << "sqrt(" << n.s << ") ";

        if (n.r > 0) {
            cout << "+ " << n.r << " ";
        } else if (n.r < 0) {
            cout << "- " << abs(n.r) << " ";
        }
    } else {
        cout << n.r << " ";
    }
}


void fraction_print(fraction f) {
    real_print(f.n);
    cout << "/ ";
    real_print(f.d);
    cout << " ";
}


void list_print(list l) {
    cout << l.i << ", ";
    fraction_print(l.f);
}


void vector_list_print(vector<list> v) {
    for (int i = 0; i < v.size(); i++) {
        list_print(v[i]);
        cout << endl;
    }
}


bool real_compare(real a, real b) {
    if (a.r == b.r && a.s == b.s) {
        return true;
    }

    return false;
}


bool fraction_compare(fraction a, fraction b) {
    if (real_compare(a.n, b.n) && real_compare(a.d, b.d)) {
        return true;
    }

    return false;
}


bool list_compare(list a, list b) {
    if (a.i == b.i && fraction_compare(a.f, b.f)) {
        return true;
    }

    return false;
}


int check_contains(vector<list> v, list l) {
    for (int i = 0; i < v.size(); i++) {
        if (list_compare(v[i], l)) {
            return i;
        }
    }

    return -1;
} 


int normalize(real n) {
    return n.s - (n.r * n.r);
}


real conjugate(real n) {
    real m;
    m.s = n.s;
    m.r = -n.r;

    return m;
}


fraction flip(fraction f) {
    fraction g;

    g.n = f.d;
    g.d = f.n;

    return g;
}


list next(fraction f) {
    list l;
    real new_n, new_d;
    fraction new_f;

    new_n = conjugate(f.d);
    new_d.s = 0;
    new_d.r = normalize(f.d);
    new_d.r /= f.n.r;

    l.i = floor((sqrt(new_n.s) + new_n.r) / new_d.r);

    new_f.n = new_n;
    new_f.d = new_d;
    new_n.r = new_n.r - new_d.r * l.i;
    new_f.n = new_n;

    l.f = flip(new_f);

    return l;
}


int period(int n) {
    vector<list> v;
    list l;
    fraction f;
    real a, b;
    int i;

    l.i = floor(sqrt(n));
    a.s = n; a.r = -floor(sqrt(n));
    b.s = 0; b.r = 1;
    f.n = b; f.d = a;
    l.f = f;

    while (true) {
        i = check_contains(v, l);

        if (i > 0) {
            break;
        }

        v.push_back(l);
        l = next(l.f);
    }

    return v.size()-i;
}


int solve(int n) {
    int count = 0;

    for (int i = 2; i <= n; i++) {
        if ((int)sqrt(i) == sqrt(i)) {
            continue;
        }

        if (period(i) % 2 == 1) {
            count++;
        }
    }

    return count;
}


int main() {
    cout << solve(10000) << endl;

    return 0;
}