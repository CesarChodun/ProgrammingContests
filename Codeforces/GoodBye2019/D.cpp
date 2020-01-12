#include <bits/stdc++.h>

#define ll long long
#define ll2 pair<ll, ll>
#define int2 pair<int, int>
#define mp make_pair
#define x first
#define y second
#define FORE(v) for (int i = 0; i < v.size(); ++i)
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

int k, n;
map<int, int2> qs;

int2 frontQuery(int ommit) {
    if (qs.find(ommit) != qs.end())
        return qs[ommit];

    cout << "?";
    FOR(i, k + 1) {
        if (i != ommit)
            cout << " " << (i + 1);
    }
    cout << "\n";
    cout.flush();

    int2 out;
    cin >> out.x >> out.y;
    qs[ommit] = out;

    return out;
}

int other(int a, int b) {
    FOR(i, n)
        if (i != a && i != b)
            return i;
    return 0;
}

void solve() {
    cin >> n >> k;
    if (k == 1) {
        cout << "! 1\n";
        return;
    }

    int2 a;
    int2 b;

    a = frontQuery(0);
    b = frontQuery(a.x - 1);

    bool aBigger = a.y > b.y;
    int smaller = 0;
    FOR(i, k + 1)
        if (i != a.x - 1) {
            int2 o = frontQuery(i);

            if (o.x != b.x)
                smaller += aBigger;
            else
                smaller += 1 - aBigger;
        }

    smaller -= aBigger;
    cout << "! " << (smaller + 1) << "\n";
}

int main() {

  solve();

  return 0;
}
