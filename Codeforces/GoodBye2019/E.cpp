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
     
    const int SIZE = 1 * 1e3 + 70;
    const ll MOD = 1e9 + 9;
     
    int N;
    vec<int2> vals;
    vec<int> group;
    vec<int> groups;
     
    #define atBit(x, lvl) (((x & (1<<lvl))) > 0)
     
    int check(const int2 &v, const int &k) {
        return atBit(v.x, k) * 2 +  atBit(v.y, k);
    }
     
    void remap(int lvl) {
        FOR(i, 4)
            groups[i] = 0;
     
        FOR(i, N) {
            group[i] = check(vals[i], lvl);
            groups[group[i]]++;
        }
    }
     
    int chooseGroup() {     
        FOR(i, 4)
            if (groups[i] != N && groups[i] != 0)
                return i;
        return -1;
    }
     
    bool checkG(int v, int g) {
        if (v == g)
            return true;
     
        if (groups[0] == 0 && groups[3] == 0)
            return false;
        if (groups[1] == 0 && groups[2] == 0)
            return false;
     
        return (g + v == 3);
    }
     
    int countGroup(int g) {
        int out = 0;
     
        FOR(i, N)
            out += checkG(group[i], g);
        
        return out;
    }
     
    void init() {
        cin >> N;
     
        group.resize(N);
        groups.resize(4);
        vals.resize(N);
     
        FOR(i, N)
            cin >> vals[i].x >> vals[i].y;
    }
     
    void prepare() {
        int k = 0;
        while(N != 2) {
            remap(k++);
            if (DEBUG)
                cout << "Remaping\n";
            if (chooseGroup() != -1)
                return;
        }
    }
     
    void solve() {
        if (N == 2) {
            cout << "1\n1\n";
            return;
        }
     
        int g = chooseGroup();
        int m = countGroup(g);
     
        cout << m << "\n";
     
        FOR(i, N)
            if (checkG(group[i], g))
                cout << i + 1 << " "; 
        
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
