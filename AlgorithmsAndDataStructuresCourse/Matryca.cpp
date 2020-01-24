#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long

using namespace std;

string s;

void read() {
    cin >> s;
}

void printVec(vector<int> vec) {
    for (int i = 0 ;i < vec.size(); i++)
        cout << vec[i] << ", ";
    cout << "\n";
}

void prepare() {}

ll solve() {
    int len = s.length();

    int c1_pos = -len - 10, c1_val = -1;
    int c2_pos = -len - 10, c2_val = -1;

    int worst = len + 10;

    for (int i = 0; i < len; i++) {
        int c = s[i];

        if (c == '*');
        else if (c == c1_val) {
            int dis = i - c2_pos - 1;
            c1_pos = i;
            worst = min(worst, dis);
        }
        else {
            int dis = i - c1_pos - 1;
            worst = min(worst, dis);

            c2_pos = c1_pos;
            c2_val = c1_val;

            c1_pos = i;
            c1_val = c;
        }
    }

    return max(1, min(len, len - worst));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    prepare();
    cout << solve() << "\n";
}
