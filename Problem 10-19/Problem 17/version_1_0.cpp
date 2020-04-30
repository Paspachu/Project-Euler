#include <iostream>
#include <vector>
using namespace std;

vector<string> base = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

vector<string> tenth = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};


int vector_sum(vector<string> v) {
    int sum = 0;

    for (int i = 0; i < v.size(); i++) {
        sum += v[i].length();
    }

    return sum;
}


int solve(int n) {
    vector<string> everything;
    
    for (int i = 1; i <= n; i++) {
        if (i < 20) {
            everything.push_back(base[i]);
        } else if (i < 100) {
            everything.push_back(tenth[(i/10)]);
            everything.push_back(base[(i%10)]);
        } else if (i < 1000) {
            everything.push_back(base[(i/100)]);
            everything.push_back("hundred");

            if (i % 100 != 0) {
                int t = i % 100;
                everything.push_back("and");
                if (t < 20) {
                    everything.push_back(base[t]);
                } else {
                    everything.push_back(tenth[(t/10)]);
                    everything.push_back(base[(t%10)]);
                }
            }

        } else {
            everything.push_back("one");
            everything.push_back("thousand");
        }
    }

    return vector_sum(everything);
} 


int main() {
    cout << solve(1000) << endl;

    return 0;
}