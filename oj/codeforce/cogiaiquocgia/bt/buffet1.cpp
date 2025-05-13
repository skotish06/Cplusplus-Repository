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
#define task ""

using namespace std;
const int N = 1e6 + 9;
int n, u, v;
pii a[N];
int p[N];
int we, va;
int ans;

void ql(int i) {
    we = va = 0;
    if (i > n) {
        for (int i = 1; i <= n; ++i) {
            if (p[i] != 0) {
                we += a[i].fi;
                va += a[i].se;
            }
            if (we >= u and we <= v) {
                ans = max(ans, va);
            }
        }
    }
    else {
        for (int j = 0; j <= 1; ++j) {
            p[i] = j;
            ql(i + 1);
        }
    }
}

void logic() {
    cin >> n >> u >> v;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    ql(1);
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
