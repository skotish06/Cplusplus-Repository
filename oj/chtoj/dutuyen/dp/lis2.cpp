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
#define task "LIS"

using namespace std;
const int N = 1e6 + 9;
int n, m;
int a[N];
int dp[N];
int f[N];
int x = INF;
vector<int> v;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = lower_bound(f + 1, f + m + 1, a[i]) - f;
        if (dp[i] > m) ++m; 
        f[dp[i]] = a[i]; 
    }
    cout << m << '\n';
    for (int i = n; i >= 1; --i) {
        if (a[i] < x and dp[i] == m) {
            --m;
            v.pb(i);
            x = a[i];
        }
    }
    reverse(all(v));
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
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
