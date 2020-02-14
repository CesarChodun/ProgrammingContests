#include <bits/stdc++.h>

#define ll long long
#define ll2 pair<ll, ll>
#define int2 pair<int, int>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define FORE(v) for (int i = 0; i < v.size(); ++i)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define SORT(v) std::sort(v.begin(), v.end())
#define DPRINT if (DEBUG) std::cout
#define PRINT_V(v) {FORE(v) std::cout << v[i] << ", "; std::cout << "\n";}
#define DPRINT_V(v) if (DEBUG) { PRINT_V(v) }
#define vec vector

#define MULTI_TASK true
#define DEBUG false
#define ALPHABET_SIZE 30

using namespace std;

const int SIZE = 1 * 1e3 + 70;
const ll MOD = 1e9 + 9;

int N, M;
vec<char> keys;
string pswd;
bitset<SIZE> used;
bool ok = true;

void init() {
    keys.resize(SIZE);

    FOR(i, SIZE)
        keys[i] = '#';

    cin >> pswd;
    used.reset();
    ok = true;
}

void prepare() {
    int len = pswd.size();
    int pos = 200;

    FOR(i, len) {
        char c = pswd[i];

        if (keys[pos - 1] == c)
            pos--;
        else if (keys[pos + 1] == c)
            pos++;
        else {
            if (used[c] == 1) {
                ok = false;
                return;
            }

            used[c] = 1;
            if (keys[pos - 1] == '#')
                keys[--pos] = c;
            else if (keys[pos + 1] == '#')
                keys[++pos] = c;
            else {
                ok = false;
                return;
            }
        }
    }
}

void solve() {
    if (!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    FOR(i, SIZE) {
        if (keys[i] != '#')
            cout << keys[i];
    }

    for (char i = 'a'; i <= 'z'; i++) {
        if (used[i] == false)
            cout << i;
    }

    cout << "\n";
}

int main() {
    if (!DEBUG) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

    if (MULTI_TASK) {
        int t;
        cin >> t;

        while (t--) {
            init();
            prepare();
            solve();
        }
    }
    else {
        init();
        prepare();
        solve();
    }

    return 0;
}
