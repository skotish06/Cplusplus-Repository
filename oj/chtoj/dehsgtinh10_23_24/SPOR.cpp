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
#define task "SPOR"

using namespace std;
const int N = 1e6 + 9;
int n;
pii a[N];
int ans;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    sort (a + 1, a + n + 1);
    int l = a[1].fi, r = a[1].se;
    for (int i = 2; i <= n; ++i) {
        if (a[i].fi <= r) {
            r = max(r, a[i].se);
        }
        else {
            ans += (a[i].fi - r - 1);
            l = a[i].fi;
            r = a[i].se;
        }
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
