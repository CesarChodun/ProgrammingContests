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
#define APPLY_ALL(a, v) a(v.begin(), v.end())
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
const int ALPH = 30;

int N, M;
string s;
vec<vec<ll>> suf;
vec<ll> opts;

int encode(char a, char b) {
    return (a - 'a') * ALPH + (b - 'a');
}

int getI(char a) {
    return a - 'a';
}

void init() {
    cin >> s;
    N = s.size();
}

void prepare() {

    suf.resize(N);
    opts.resize(ALPH * ALPH + 10000, 0);

    suf[N - 1].resize(ALPH, 0);
    suf[N - 1][getI(s[N - 1])] = 1;

    for(int i = N - 2; i >= 0; i--) {
        suf[i].resize(ALPH, 0);

        FOR(j, ALPH)
            suf[i][j] = suf[i + 1][j];
        
        suf[i][getI(s[i])]++;
    }
}

void solve() {

    FOR(j, ALPH) 
        FOR(i, N)
            if (getI(s[i]) == j)
                FOR(k, ALPH) 
                    opts[j * ALPH + k] += suf[i][k] - (j == k);
        
    ll out = 0;

    FOR (i, ALPH)
        out = max(out, suf[0][i]);

    FOR (i, opts.size())
        out = max(out, opts[i]);

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
