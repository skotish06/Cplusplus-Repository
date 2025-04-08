#include <bits/stdc++.h>
#define int long long
#define MOD 111539786
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "DNPK"

using namespace std;
const int N = 1e3 + 9;
int n, k;
int dp[N][N];
int res;

void logic() {
    while (cin >> n >> k) {
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][0] = (dp[i][0] + dp[i - 1][j]) % MOD;
            }
            for (int j = 1; j < k; ++j) {
                dp[i][j] = dp[i - 1][j - 1];            
            }
        }
        res = 0;
        for (int i = 1; i <= k; ++i) {
            res = (res + dp[n][i - 1]) % MOD;
        }
        cout << res << '\n';
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
