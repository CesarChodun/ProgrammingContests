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
#define vec vector

#define MULTI_TASK false
#define DEBUG false

#define ALPHABET_SIZE 30

using namespace std;

const int SIZE = 2 * 1e5 + 70;
const ll MOD = 1e9 + 9;

int N;
vec<int> types;
vec<vec<int> > links;
vec<int> perType;

vec<int> dis;
void dfs(int node, int last) {
    FORE(links[node]) {
        int p = links[node][i];

        if (p != last){
            dis[p] = dis[node] + 1;
            dfs(p, node);
        }
    }
}

int mostDistant(int type) {
    int out = -1;
    int distance = -1;

    FOR(i, N)
        if (distance < dis[i] && types[i] == type) {
            distance = dis[i];
            out = i;
        }

    return out;
}

void init() {
    cin >> N;

    types.resize(N);
    links.resize(N);
    dis.resize(N);

    perType.resize(10, -1);

    FOR(i, N) {
        cin >> types[i];
        types[i]--;
        perType[types[i]] = i;
    }

    FOR(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        links[a].pb(b);
        links[b].pb(a);
    }
}

void prepare() {
}

void solve() {
    int out = 0;

    FOR(i, 10) 
        if (perType[i] != -1) {
            dis[perType[i]] = 0;
            dfs(perType[i], -1);

            int d = mostDistant(i);
            if (d != -1) {
                dis[d] = 0;
                dfs(d, -1);
                out = max(out, dis[mostDistant(i)]);
            }
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

        while (t--)
            solve();
    }
    else {
        init();
        prepare();
        solve();
    }
    return 0;
}
