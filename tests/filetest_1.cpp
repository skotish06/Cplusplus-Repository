#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "SPASTA"

using namespace std;
const int N = 1e6 + 9;
int m, k, n, t;
int a[N], i, ans;

void logic() {
    cin >> m >> k >> n >> t;
    if (m - n < k) {
        cout << -1;
        return;
    }
    ans = k * t;
    ans += k * (k + 1) / 2;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; ++i) {
        if (a[i] <= k) {
            ans -= a[i];
            k += 1;
            ans += k;
        }
        else break;
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

    logic();

    return 0;
}
