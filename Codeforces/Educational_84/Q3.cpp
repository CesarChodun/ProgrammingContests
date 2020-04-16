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

#define MULTI_TASK false
#define DEBUG false
#define ALPHABET_SIZE 30

using namespace std;

const int SIZE = 1 * 1e5 + 70;
const ll MOD = 1e9 + 9;

int N, M, K;

void init() {
    cin >> N >> M >> K;

    int x;
    FOR(i, K * 4)
        cin >> x;
}

void prepare() {

}

void solve() {
    vector<char> out;

    FOR(i, N - 1)
        out.pb('D');
    FOR(i, M - 1)
        out.pb('L');

    FOR(i, N) {
        FOR(j, M - 1) {
            if (i % 2 == 0)
                out.pb('R');
            else
                out.pb('L');
        }

        if (i != N - 1)
            out.pb('U');
    }

    if (out.size() == 0) {
        cout << "1\nR\n";
    }
    else {
        cout << out.size() << "\n";
        FORE(out)
            cout << out[i];
        cout << "\n";
    }
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
