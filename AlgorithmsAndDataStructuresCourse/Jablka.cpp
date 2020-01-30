#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>

#define ll long long
#define int2 pair<int, int>
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

const ll MD = 1e9;

int n, d;
vector<int2> links;
vector<int> dyn[2];

void read() {
	cin >> n >> d;

	links.reserve(n);

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		links.PB(MP(x, y));
	}
}

void prepare() {
	dyn[0].resize(n + 1, 1);
	dyn[1].resize(n + 1, 1);

	for (int i = 0; i < d; i++) {
		int a = i % 2;
		int b = (a + 1) % 2;

		for (size_t i = 1; i < dyn[a].size(); i++)
			dyn[b][i] = (dyn[a][links[i - 1].X] + dyn[a][links[i - 1].Y] + 1) % MD;
	}

	int l = d % 2;
	dyn[l][0] = 1;
	for (int i = 1; i < links.size() + 1; i++)
		dyn[l][i] = (dyn[l][links[i - 1].X] + dyn[l][links[i - 1].Y] + 1) % MD;
}

void solve() {
	int a = (d - 1) % 2;
	int b = d % 2;

	ll ans = dyn[b][n] - dyn[a][n];
	if (ans < 0)
		ans += MD;

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	prepare();
	solve();

	return 0;
}
