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

const int SIZE = 1 * 1e5 + 170;
const ll MOD = 1e9 + 9;

int N, M;
vec<int> tab;
vec<int> out;
int last;
bool ok;

void init() {
    cin >> N >> M;
    ok = true;

    ll sum = 0;
    tab.resize(M);
    FOR(i, M) {
        cin >> tab[i];
        sum += tab[i];
    }

    if (sum < N)
        ok = false;
}


void prepare() {
    last = N - 1;
    int toEnd = 0;
    out.resize(M);

    for (int i = M - 1; i >= 0; i--) {
        if (last < 0) {
            ok = false;
            break;
        }
        int x = tab[i];

        int nlast = min(last - 1, N - x - 1);
        out[i] = nlast + 2;

        last = nlast;
    }

    int missing = out[0] - 1;
    DPRINT << "Miss:" << missing << "\n";

    int ssb = 0;
    for(int i = M - 2; i >= 0; i--) {
        if (missing > 0) {
            int sb = min(missing, tab[i] - 1);
            ssb += sb;
            missing -= sb;
        }
        
        DPRINT << "s: " <<  ssb << "\n";
        out[i] -= ssb;
    }

    if (missing > 0)
        ok = false;
}

void solve() {

    if (!ok || out[0] <= 0)
        cout << "-1\n";
    else {
        FOR(i, M) {
            cout << out[i] << " ";
        }

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
