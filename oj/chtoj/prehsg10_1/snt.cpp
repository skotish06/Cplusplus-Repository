#include <bits/stdc++.h>
#define int long long
#define task ""
using namespace std;
const int N = 1e6 + 9;
int n, m;
int a[2 * N], k;
bool f[2 * N];

void sieve() {
    memset(f, true, sizeof(f));
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (f[i]) {
            for (int j = i * i; j < N; j += i) {
                f[j] = false;
            }
        }
    }
}

int ptso(int x) {
    int ans = 0;
    while (x != 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {
    sieve();
    for (int i = 1; i <= 2 * N; ++i) {
        if (f[ptso(i)] and f[i]) {
            a[++k] = i;
        }
    }
    cin >> n >> m;
    int l = lower_bound(a + 1, a + k + 1, n) - a;
    int r = lower_bound(a + 1, a + k + 1, m) - a;
    cout << l << ' ' << r;
    
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
