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

const int SIZE = 2 * 1e5 + 70;
const ll MOD = 1e9 + 9;

int N, M;
vec<int> tab;
vec<int> all;
vec<int> from;

bitset<SIZE> lok, rok;

ll getSum(ll x) {
    if (x == 0)
        return 0;

    return ((1 + x) * x) / 2;
}

void init() {
    cin >> N;

    tab.resize(N);

    FOR(i, N) {
        cin >> tab[i];
    }
}

void clean() {
    FOR(i, N) {
        // lok[tab[i]] = 0;
        // rok[tab[i]] = 0;
        from[tab[i]] = 0;
    }
}

void prepare() {
    clean();

    ll lsum = 0;
    FOR(i, N) {
        int x = tab[i];
        lsum += x;

        if (from[x] == 1) {
            for (int j = i; j < N; j++)
                lok[j] = 0;

            break;
        }
        else if (from[x] == 0 && lsum == getSum(i + 1)) {
            lok[i] = 1;
        }
        else
        {
            lok[i] = 0;
        }

        from[x]++;
    }

    clean();

    ll rsum = 0;
    for (int i = N - 1; i >= 0; i--) {
        int x = tab[i];
        rsum += x;

        if (from[x] == 1) {
            for (int j = i; j >= 0; j--)
                rok[j] = 0;

            break;
        }
        else if (from[x] == 0 && rsum == getSum((N - i))) {
            rok[i] = 1;
        }
        else
        {
            rok[i] = 0;
        }

        from[x]++;
    }
}

void solve() {
    vec<int> out;

    DPRINT << "LOK:";
    FOR(i, N) {
        DPRINT << lok[i] << " ";
    }
    DPRINT << "\n";
    DPRINT << "ROK:";
    FOR(i, N) {
        DPRINT << rok[i] << " ";
    }
    DPRINT << "\n";

    FOR(i, N - 1) {
        if (lok[i] == 1 && rok[i + 1] == 1) {
            out.push_back(i);
        }
    }

    cout << out.size() << "\n";
    FORE(out) {
        cout << out[i] + 1 << " " << (N - out[i]) - 1 << "\n";
    }
}

int main() {
    all.resize(SIZE);
    from.resize(SIZE);
    lok.reset();
    rok.reset();

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
