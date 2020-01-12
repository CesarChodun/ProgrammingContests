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

int n;
vector<int> tab;

void init() {
    cin >> n;

    tab.resize(n);

    FOR(i, n)
        cin >> tab[i];
}

void solve() {
    FOR(i, n - 1) {
        if (abs(tab[i] - tab[i+1]) > 1) {
            cout << "YES\n";
            cout << (i+1) << " " << (i+2) << "\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--) {
      init();
      solve();
  }

  return 0;
}
