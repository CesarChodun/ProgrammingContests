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
    unsigned ll sum = 0, xsum = 0;

    int n;
    cin >> n;

    FOR(i, n) {
        int x;
        cin >> x;

        sum += x;
        xsum ^= x;
    }


    vector<ll> out;
    out.push_back(xsum);
    sum += xsum;

    out.push_back(sum);

    cout << out.size() << "\n";
    cout << out[0] << " " << out[1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
      solve();
  }

  return 0;
}
