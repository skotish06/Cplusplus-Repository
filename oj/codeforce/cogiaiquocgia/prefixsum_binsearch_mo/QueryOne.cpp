#include <bits/stdc++.h>
#define int long long
#define task ""
using namespace std;
const int N = 1e6 + 9;
int n;
int a[N], pref[N];
int l, r, k;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    cin >> k;
    while (k--) {
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
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
