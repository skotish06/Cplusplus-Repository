#include <bits/stdc++.h>
#define int long long
#define task ""
using namespace std;
const int N = 1e6 + 9;
int n

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ans += cnt[a[i] % 2];
        ++cnt[a[i] % 2];
    }
    cout << ans;
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
