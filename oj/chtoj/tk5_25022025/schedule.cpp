#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a, n) (a) + 1, (a) + (n) + 1
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "SCHEDULE"

using namespace std;
const int N = 1e6 + 9;
int n;
pii a[N];
int pre[N];
int ans;

bool cmp(pii x, pii y) {
    // x.fi / x.se > y.fi / y.se
    // x.fi * y.se > x.se * y.fi
    return x.fi * y.se > x.se * y.fi;
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].se;
    }
    sort (a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i].se;
    } 
    for (int i = 1; i <= n; ++i) {
        ans += pre[i] * a[i].fi;
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
