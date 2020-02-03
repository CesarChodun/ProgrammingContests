#include <vector>
#include <iostream>
#include <stack>
#include <cassert>
#include <algorithm>
#include <set>

#define int2 pair<int, int>
#define X first
#define Y second
#define MP make_pair
#define PB push_back

using namespace std;

const int MAX_INT = 2e9;
const int TREE_DEPTH = 21;
const int TREE_SIZE = 1 << TREE_DEPTH;
const int NODES_COUNT = TREE_SIZE / 2;

int N, M;

int tree[TREE_SIZE + 9];
vector<int2> range;

void paintRoad(int node, bool black) {
    if (black)
        tree[node] = MAX_INT;
    else
        tree[node] = -1;
}

void pushData(int node) {
    if (node >= NODES_COUNT)
            return;
    if (tree[node] == -1 || tree[node] == MAX_INT) {
        tree[node << 1] = tree[node];
        tree[(node << 1) + 1] = tree[node];

        tree[node] = 0;
    }
}

int getBlack(int node) {
    if (tree[node] == -1)
        return 0;
    if (tree[node] == MAX_INT)
        return range[node].Y - range[node].X + 1;

    return tree[node];
}

void calculate(int node) {
    if (node >= NODES_COUNT) {
        if (tree[node] == MAX_INT)
            tree[node] = 1;
        else
            tree[node] = max(tree[node], 0);

        return;
    }

    int sum = 0;

    sum += getBlack(node << 1);
    sum += getBlack((node << 1) + 1);

    tree[node] = sum;
}

void applyInRange(int rx, int ry, int node, bool black) {
    pushData(node);

    if (rx <= range[node].X && ry >= range[node].Y);
    else if (rx > range[node].Y || ry < range[node].X);
    else {
        applyInRange(rx, ry, node << 1, black);
        applyInRange(rx, ry, (node << 1) + 1, black);
    }

    if (rx <= range[node].X && ry >= range[node].Y)
        paintRoad(node, black);
    else
        calculate(node);
}

void init() {
    cin >> N >> M;
}

void prepare() {
    range.resize(TREE_SIZE + 9);

    for (int i = 0; i < NODES_COUNT; i++)
        tree[NODES_COUNT + i] = 0;
    for (int i = 0; i < N; i++)
        tree[NODES_COUNT + i] = 1;

    for (int i = NODES_COUNT; i < TREE_SIZE + 1; i++)
        range[i] = MP(i - NODES_COUNT, i - NODES_COUNT);

    for (int i = NODES_COUNT - 1; i > 0; i--) {
        tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        range[i] = MP(range[i << 1].X, range[(i << 1) + 1].Y);
    }
}

void solve() {
    int a, b;
    char c;


    while (M--) {
        cin >> a >> b; a--; b--;
        cin >> c;

        bool isBlack = (c == 'C');

        applyInRange(a, b, 1, isBlack);

        cout << (N - tree[1]) << "\n";
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    prepare();
    solve();

    return 0;
}
