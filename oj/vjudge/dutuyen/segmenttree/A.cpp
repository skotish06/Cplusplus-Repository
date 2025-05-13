#include <bits/stdc++.h>
// #include <iostream>
#define int long long
#define range(i, l, r) for(int i = l; i <= r; ++i)
#define task "querysum"
using namespace std;
const int N = 1e6 + 9;
int n, m;
int a[N];
int tree[4 * N];
int l, r;

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }
    if (l == r) {
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    tree[id] = tree[2 * id] ^ tree[2 * id + 1];
}

int get(int id, int l, int r, int u, int v) {
    /// [l r] [u v] [l r] 
    if (r < u || l > v) { 
        return 0;
    }
    /// [u l r v]
    if (l >= u && r <= v) { 
        return tree[id];
    }
    int mid = (l + r) / 2;
    return get(2 * id, l, mid, u, v) ^ get(2 * id + 1, mid + 1, r, u, v);
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        update(1, 1, n, i, a[i]); 
    }
    while (m--) {
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << '\n'; 
    }
}
int32_t main(){
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(fopen(task ".inp", "r"))
        {
            freopen(task ".inp", "r", stdin);
            freopen(task ".out", "w", stdout);
        }
    }
    solve();
}
