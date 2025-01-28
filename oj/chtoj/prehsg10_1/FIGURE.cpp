#include <bits/stdc++.h>
#define int long long
#define task "FIGURE"
using namespace std;
const int N = 1e6 + 9;
const int M = 1e9 + 7;
int n, m;

int f(int x) {
    int res = 1;
    for (int i = 2; i <= x; i++) {
        res = (res * i) % M;
    }
    return res;
}

void solve() {
    cin >> n >> m;
    int v1 = (f(n) * f(m) % M * 2) % M;
    int v2 = (f(n) * f(m)) % M;
    cout << ((n == m) ? v1 : v2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();
    return 0;
}