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
#define task "MMSEG"

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
int q;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int minn = *min_element(a + 1, a + n + 1);
    int maxx = *max_element(a + 1, a + n + 1);
    int ans = LLONG_MAX;
    int l = -1, r = -1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == maxx) {
            if (l != -1) {
                ans = min(ans, i - l + 1);
            }
            r = i;
        }
        if (a[i] == minn) {
            if (r != -1) {
                ans = min(ans, i - r + 1);
            }
            l = i;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> q;
    while(q--) {
        logic();
    }

    return 0;
}
