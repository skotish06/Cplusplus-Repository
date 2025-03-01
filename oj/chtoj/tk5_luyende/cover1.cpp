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
#define task "COVER1"

using namespace std;

const int N = 1e6 + 9;
int n;
pii a[N];

bool cmp(pii x, pii y) {
    return x.se < y.se;
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    int f = a[1].fi, s = a[1].se;
    for (int i = 2; i <= n; ++i) {
        if (a[i].fi > s) {  
            ans += (s - f);
            f = a[i].fi;
            s = a[i].se;
        } else {
            s = max(s, a[i].se);
        }
    }
    ans += (s - f);
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