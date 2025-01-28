#include <bits/stdc++.h>
#define int long long
#define task ""
using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
int k, x;

int bin_search(int x) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    while (k--) {
        cin >> x;
        if (binary_search(a + 1, a + n + 1, x))
            cout << bin_search(x) << '\n';
        else cout << -1 << '\n';
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
