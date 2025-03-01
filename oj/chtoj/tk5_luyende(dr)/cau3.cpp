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
#define task "cau3"

using namespace std;
const int N = 1e6 + 9;
int n, m;
int a[N];
int s;
int ans = LLONG_MAX;

void logic() {
    cin >> n >> m;
    int l = 1;
    for (int r = 1; r <= n; ++r) {
        cin >> a[r];
        s += a[r];
        while (s >= m) {
            ans = min(ans, r - l + 1);
            s -= a[l];
            ++l;
        }
    }
    if (ans == LLONG_MAX) {
        cout << -1;
    }
    else cout << ans;
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
