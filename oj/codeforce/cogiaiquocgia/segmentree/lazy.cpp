#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 9;
int n, m;
int a[N], lazy[4 * N], tree[4 * N];

void down(int id) {
    if (lazy[id]) {  
        int x = lazy[id];

        lazy[id * 2] += x;
        tree[id * 2] += x;

        lazy[id * 2 + 1] += x;
        tree[id * 2 + 1] += x;

        lazy[id] = 0; 
    }
}

// a[u -> v] += val
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) {
        return;
    }
    if (l >= u && r <= v) {
        tree[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) {
        return -1e18;
    }
    if (l >= u && r <= v) {
        return tree[id];
    }
    int mid = (l + r) / 2;
    down(id);
    return max(get(2 * id, l, mid, u, v), 
               get(2 * id + 1, mid + 1, r, u, v));
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int type; cin >> type;
        if (type == 0) {  
            int l, r, k; cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        } else {  
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
