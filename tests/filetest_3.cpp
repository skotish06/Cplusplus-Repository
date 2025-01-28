#include <bits/stdc++.h>
#define int long long
#define range(i, l, r) for(int i = l; i <= r; ++i)
#define task ""
using namespace std;
const int N = 1e6 + 9;

int n, m;
int c;
int pos, k, l, r;
int tree[4 * N];

void build (int id, int l, int r, int pos, int val) {
    /// pos [l r] pos
    if (pos < l or pos > r) {
        return;
    }
    if (l == r) {
        tree[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid, pos, val);
    build(2 * id + 1, mid + 1, r, pos, val);
    tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}


int get(int id, int l, int r, int u, int v) {
    /// [l r] [u v] [l r]
    if (u > r or v < l) {
        return -1e18;
    }
    /// [u l r v] 
    if (l >= u and r <= v) {
        return tree[id];
    }
    int mid = (l + r) / 2;
    return max(get(2 * id, l, mid, u, v), 
               get(2 * id + 1, mid + 1, r, u, v));
}

void solve(){
    cin >> n >> m;
    while (m--) {
        cin >> c >> l >> r;
        if (c == 0) {
            build (1, 1, n, l, r);
        }
        else {
            cout << get(1, 1, n, l, r) << '\n';
        }
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