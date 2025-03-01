#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define SORT(a, n) sort((a) + 1, (a) + (n) + 1)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "MEET"

using namespace std;
const int N = 1e6 + 9;
int n, q;
int a[N];
int p[N];

void bruteforce() {
    while(q--) {
        int ans = LLONG_MAX;
        int x, y; cin >> x >> y;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, max(abs(a[x] - a[i]), abs(a[y] - a[i])));
        }
        cout << ans << '\n';
    }
}

void optimized() {
    SORT(a, n);
    while(q--) {
        int x, y; cin >> x >> y;
        int z = lower_bound(a + 1, a + n + 1, (p[x] + p[y]) >> 1) - p;
        cout << min(max(abs(p[x] - p[z]), abs(p[y] - p[z])),
                    max(abs(p[x] - p[z - 1]), abs(p[y] - p[z - 1]))) << '\n';
    }
}


void cntsqr() {
    for (int i = 1; i * i <= N; ++i) {
        int sq = i * i;
        for (int j = sq; j <= N; j += sq) {
            ++f[j];
        }
    }
}

void logic() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = a[i];
    }
    if (n <= 100 and q <= 100) {
        bruteforce();
    }
    else {
        optimized();
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

    logic();

    return 0;
}
