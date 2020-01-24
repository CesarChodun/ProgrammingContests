#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

int N;
vector<int> tab, min_even, min_odd, max_even, max_odd;
vector<ll> pref;

void read() {
  cin >> N;

  tab.reserve(N);
  max_even.resize(N);
  max_odd.resize(N);
  min_even.resize(N);
  min_odd.resize(N);
  pref.resize(N);

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    tab.push_back(a);
  }
}

ll maxLL(ll a, ll b) {
    if (a > b)
        return a;
    return b;
}

ll minLL(ll a, ll b) {
    if (a < b)
        return a;
    return b;
}

void prepare() {

    reverse(tab.begin(), tab.end());

    min_even[0] = -1;
    min_odd[0] = -1;

    pref[0] = tab[0];
    if (tab[0] % 2 == 0)
        min_even[0] = tab[0];
    else
        min_odd[0] = tab[0];

    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + (ll)tab[i];

        if (tab[i] % 2 == 0) {
            min_even[i] = tab[i];
            min_odd[i] = min_odd[i - 1];
        }
        else {
            min_even[i] = min_even[i - 1];
            min_odd[i] = tab[i];
        }
    }

    max_even[N - 1] = -1;
    max_odd[N - 1] = -1;

    if (tab[N - 1] % 2 == 0)
        max_even[N - 1] = tab[N - 1];
    else
        max_odd[N - 1] = tab[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        if (tab[i] % 2 == 0) {
            max_even[i] = tab[i];
            max_odd[i] = max_odd[i + 1];
        }
        else {
            max_even[i] = max_even[i + 1];
            max_odd[i] = tab[i];
        }
    }
}

ll solve() {
    int k;
    cin >> k;

    ll ans = pref[k - 1];

    ll rem = 0;

    if (k == N) {
        if (ans % 2 == 0)
            ans = -1;
    }
    else if (ans % 2 != 1) {
        rem = -1;

        if (max_odd[k] != -1 && min_even[k-1] != -1)
            rem = min_even[k-1] - max_odd[k];
        if (min_odd[k-1] != -1 && max_even[k] != -1)
            rem = minLL(rem, min_odd[k-1] - max_even[k]);

        if (rem == -1) {
          ans = -1;
          rem = 0;
        }
    }

    return (ans - rem);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    prepare();

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
      cout << solve() << "\n";
}
