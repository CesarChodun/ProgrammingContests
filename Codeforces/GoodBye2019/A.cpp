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

void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    int aMax = 0, bMax = 0;

    FOR(i, k) {
        int x;
        cin >> x;

        aMax = max(aMax, x);
    }

    FOR(i, d) {
        int x;
        cin >> x;

        bMax = max(bMax, x);
    }

    if (aMax > bMax)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  FOR(i, t)
    solve();

  return 0;
}
