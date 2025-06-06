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
#define task "NKTICK"

using namespace std;
const int N = 1e6 + 9;
int n;
int t[N], r[N], dp[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        cin >> r[i];
    }
    /*
        dp[i - 1] + t[i];
        dp[i - 2] + r[i - 1];
    */
    dp[1] = t[1];
    dp[2] = min(t[1] + t[2], r[1]);
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
    }
    cout << dp[n];
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
