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
#define task "FLOWERS"

using namespace std;
const int N = 1e6 + 9;
int n, k;
pair<int, string> a[N];
unordered_map<string, int> cnt;
int maxc;

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n - k; ++i) {
        for (int j = i; j <= k; ++j) {
            ++cnt[a[i].se];
            maxc = max(maxc, cnt[a[i].se]);
        }
        for (int j = i; j <= k; ++j) {
            --cnt[a[i].se];
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[i].se == a[j].se) {
                ++cnt[a[i].se];
                maxc = max(maxc, cnt[a[i].se]);
            }
        }
        for (int j = i + 1; j <= n; ++j) {
            if (a[i].se == a[j].se) {
                --cnt[a[i].se];
            }
        }
        cnt.clear();
    }

    cout << maxc << '\n';
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
