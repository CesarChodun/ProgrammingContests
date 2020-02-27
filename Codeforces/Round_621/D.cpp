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

int N, M, K;

vec<int> spec;
vec<int> dis1, dis2;
vec<vec<int>> links;

vec<int> bpath;

void bfs(vec<int> &dis, int p) {
    queue<int2> q;
    dis[p] = 0;
    q.push(mp(p, 0));

    while(q.size()) {
        int2 d = q.front();
        q.pop();

        FOR(i, links[d.x].size()) {
            int a = links[d.x][i];

            if (dis[a] > d.y + 1)
                q.push(mp(a, d.y + 1));

            dis[a] = min(dis[a], d.y + 1);
        }
    }
}

void init() {
    cin >> N >> M >> K;

    spec.resize(K);
    links.resize(N);
    dis1.resize(N, N * 2);
    dis2.resize(N, N * 2);

    FOR(i, K) {
        cin >> spec[i];
        spec[i]--;
    }

    FOR(i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        links[x].pb(y);
        links[y].pb(x);
    }
}

void prepare() {
    bfs(dis1, 0);
    bfs(dis2, N - 1);
}

void upd(vec<vec<int2>> &v, int d1, int2 p) {
    if (v[d1][0] < p) {
        v[d1][1] = v[d1][0];
        v[d1][0] = p;
    }
    else if (v[d1][1] < p) {
        v[d1][1] = p;
    }
}

int compose(vec<vec<int2>> &v, int d1, int id) {
    if (v[d1][0].y != id) {
        return v[d1][0].x + d1 + 1;
    }

    return v[d1][1].x + d1 + 1;
}

void solve() {
    vec<vec<int2>> v;
    v.resize(N); 

    FOR(i, N) {
        v[i].resize(2);

        FOR(j, 2)
            v[i][j] = mp(-N - 100, -N -100);
    }


    FOR(i, K) {
        int p = spec[i];

        DPRINT << p << "\n";

        int d1 = dis1[p];
        int d2 = dis2[p];
        
        upd(v, d1, mp(d2, p));
    }

    for (int i = N - 1; i > 0; i--) {
        upd(v, i - 1, v[i][0]);
        upd(v, i - 1, v[i][1]);
    }

    int out = 0;

    FOR(i, K) {
        int p = spec[i];
        out = max(out, compose(v, dis1[p], p));
    }

    cout << min(out, dis1[N - 1]) << "\n";
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
