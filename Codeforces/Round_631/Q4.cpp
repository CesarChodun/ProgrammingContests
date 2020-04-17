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

ll N, M;

ll sumM(ll a, ll b) {
    return (a + b) % M;
}

ll mullM(ll a, ll b) {
    return (a * b) % M;
}

void init() {
    cin >> N >>  M;
}

void prepare() {}

void solve() {
    ll bbit = N;

    int k = 0;
    while (bbit != 1) {
        k++;
        bbit >>= 1;
    }

    bbit <<= k;
    DPRINT << "BBit: " << bbit << "\n";

    ll out = 0;
    ll d = N - bbit;

    out = sumM(out, d + 1);
    DPRINT << "U: " << out << "\n";

    while (bbit > 1) {
        ll hwm = bbit - (bbit >> 1);

        out = sumM(out, mullM(out + 1, hwm % M));
        DPRINT << "U: " << out << " " << hwm << " " << bbit << "\n";

        bbit >>= 1;
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
