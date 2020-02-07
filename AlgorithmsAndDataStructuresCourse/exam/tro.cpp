#include <bits/stdc++.h>

#define ll long long
#define ll2 pair<ll, ll>
#define int2 pair<int, int>
#define mp make_pair
#define x first
#define y second
#define FORE(v) for (int i = 0; i < v.size(); ++i)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define vec vector

#define MULTI_TASK false
#define DEBUG false

#define ALPHABET_SIZE 30

using namespace std;

const ll MOD = 1e9 + 9;
const int SIZE = 5 * 1e5 + 20;

vec<int> vals;
int pref[10][SIZE];

int N;

int query(int s, int e, int p) {
    if (p < 0 || p > 9 || s == -1)
        return 0;

    if (s == 0)
        return pref[p][e];
    return pref[p][e] - pref[p][s - 1];
}

void init() {
    cin >> N;

    vals.resize(N, 0);

    FOR(i, N)
        cin >> vals[i];
}

void prepare() {
    FOR(j, 10) {
        pref[j][0] = (vals[0] == (j + 1));

        for (int i = 1; i < N; i++) 
            pref[j][i] = pref[j][i - 1] + (vals[i] == (j + 1));
    }
}

void solve() {
    uint64_t out = 0;

    FOR(i, N) {
        int a;
        int b = vals[i];

        FOR(j, 10){
            a = j;

            out += (ll)query(0, i - 1, a) * query(i + 1, N - 1, a + b);
        }
    }

    cout << out << "\n";
}

int main() {
    if (!DEBUG) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

    if (MULTI_TASK) {
        int t;
        cin >> t;

        while (t--)
            solve();
    }
    else {
        init();
        prepare();
        solve();
    }

    return 0;
}
