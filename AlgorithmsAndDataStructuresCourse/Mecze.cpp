#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int N, M;
vector<ll> players;

void read() {
    cin >> N >> M;
    
    players.resize(N, 0);

    int x;
    for(int i = 0; i < M; i++) 
        for (int j = 0; j < N; j++) {
            cin >> x;
            if (j < N/2)
                players[x - 1] += ((ll) 1) << i; 
        }
}

void prepare() {}

bool solve() {
    sort(players.begin(), players.end());

    ll last = (ll)1 << M; 
    for (size_t i = 0; i < players.size(); i++) {
        if (last == players[i])
            return false;

        last = players[i];
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    prepare();

    if (solve())
        cout << "TAK\n";
    else
        cout << "NIE\n";
}
