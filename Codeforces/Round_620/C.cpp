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

const int SIZE = 1 * 1e5 + 70;
const ll MOD = 1e9 + 9;

int N, M;

vec<pair<int, int2> > temps;

void init() {
    cin >> N >> M;

    temps.resize(N);

    FOR(i, N)
        cin >> temps[i].x >> temps[i].y.x >> temps[i].y.y;
}

void prepare() {
    SORT(temps);
}

void solve() {
    int time = 0;
    int2 range = mp(M, M);

    FOR(i, N) {
        int dtime = temps[i].x - time;
        int2 range2 = mp(max(range.x - dtime, temps[i].y.x), min(range.y + dtime, temps[i].y.y));

        if (range2.y < temps[i].y.x || range2.x > temps[i].y.y) {
            cout << "NO\n";
            return;
        }

        range = range2;
        time = temps[i].x;
    }

    cout << "YES\n";
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
