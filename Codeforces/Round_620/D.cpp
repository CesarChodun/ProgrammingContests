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
vec<char> tab;
set<int2> unused;

void rotateP(vec<int> &out, int a, int b) {
    reverse(out.begin() + a, out.begin() + b);
}

vec<int> create(bool flip) { //flip == false  => less
    vec<int> out;

    out.resize(N);

    FOR(i, N) {
        int k = i + 1;
        if (!flip)
            k = N - k + 1;

        out[i] = k;
    }

    int last = 0;

    FOR(i, N) {
        if (!flip) {
            if (tab[i] == '<');
            else {
                rotateP(out, last, i + 1);
                last = i + 1;
            }
        }
        else {
            if (tab[i] == '>');
            else {
                rotateP(out, last, i + 1);
                last = i + 1;
            }
        }
    }

    rotateP(out, last, N);

    return out;
}

void init() {
    cin >> N;

    tab.resize(N);

    FOR(i, N - 1)
        cin >> tab[i];
}

void prepare() {
}

void solve() {
    vec<int> out = create(false);
    vec<int> out2 = create(true);

    FOR(i, N)
        cout << out[i] << " ";
    cout << "\n";

    FOR(i, N)
        cout << out2[i] << " ";
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
