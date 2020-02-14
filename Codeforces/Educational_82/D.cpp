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

unsigned ll N, M;
vec<int> tab;
int out;
bool ok;

int power(unsigned ll x) {
    int out = 0;

    while (x != 1) {
        out++;
        x >>= 1;
    }

    return out;
}

void split(int needed) {
    int o = -1;
    for (int i = needed + 1; i < 100; i++)
        if (tab[i] != 0) {
            o = i;
            break;
        }

    if (o == -1) {
        ok = false;
        return;
    }

    tab[o]--;

    for (int i = o - 1; i > needed; i--) {
        tab[i]++;
        out += 1;
    }

    out++;
    tab[needed] += 2;
}

void init() {
    cin >> N >> M;

    tab.resize(100);
    FOR(i, 100)
        tab[i] = 0;

    FOR(i, M) {
        unsigned ll a;
        cin >> a;

        tab[power(a)]++;
    }

    out = 0;
    ok = true;
}

void prepare() {

}

void solve() {
    int k = 0;

    while (N != 0) {
        if ((N % 2) == 1) {
            if (tab[k] > 0) ;
            else
                split(k);

            tab[k]--;
        }

        N >>= 1;

        tab[k + 1] += tab[k] / 2;
        k++;
    }

    if (ok)
        cout << out << "\n";
    else
        cout << -1 << "\n";
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
