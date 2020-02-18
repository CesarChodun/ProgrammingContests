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

int N, M;

vec<string> strs;
vec<vec<int>> sim; 
bitset<200> used;

bool isP(string a) {
    FOR(i, M)
        if (a[i] != a[M - i - 1])
            return false;
    return true;
}

bool compareP(string a, string b) {
    reverse(b.begin(), b.end());

    FOR(i, M)
        if (a[i] != b[i])
            return false;
    return true;
}

void init() {
    cin >> N >> M;

    used.reset();
    strs.resize(N);
    sim.resize(N);
    FOR(i, N)
        sim[i].clear();

    FOR(i, N)
        cin >> strs[i];
}

void prepare() {
    FOR(i, N) {
        FOR(j, N) {
            if (compareP(strs[i], strs[j]) && i != j)
                sim[i].pb(j);
        }
    }
}

void solve() {
    vec<string> beg;
    vec<string> end;

    FOR(i, N) {
        if (used[i] == 0) {
            int found = -1;

            FOR(j, sim[i].size()) 
                if (used[sim[i][j]] == 0) {
                    used[sim[i][j]] = 1;
                    found = sim[i][j];
                }

            if (found != -1) {
                used[i] = true;
                beg.pb(strs[i]);
                end.pb(strs[found]);
            }
        }
    }

    int pl = -1;
    FOR(i, N)
        if (used[i] == 0 && isP(strs[i])) {
            pl = i;
            break;
        }

    reverse(end.begin(), end.end());

    string out = "";

    FOR(i, beg.size())
        out += beg[i];

    if (pl != -1)
        out += strs[pl];

    FOR(i, end.size())
        out += end[i];

    cout << out.size() << "\n";
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
