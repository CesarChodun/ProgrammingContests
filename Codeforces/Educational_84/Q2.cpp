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
bitset<SIZE> taken;
int quen;

void init() {
    cin >> N;
    quen = -1;
    taken.reset();

    FOR(i, N) {
        int m;
        bool ok = false;
        cin >> m;

        FOR(j, m) {
            int x;
            cin >> x;
            x--;

            if (!ok && taken[x] == 0) {
                ok = true;
                taken[x] = 1;
            }
        }

        if (!ok)
            quen = i;
    }
}

void prepare() {}

void solve() {
    if (quen == -1)
        cout << "OPTIMAL\n";
    else {
        cout << "IMPROVE\n";

        int castle = -1;
        FOR(i, N)
            if (taken[i] == 0) {
                castle = i;
                break;
            }

        cout << quen + 1 << " " << castle + 1 << "\n";
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
