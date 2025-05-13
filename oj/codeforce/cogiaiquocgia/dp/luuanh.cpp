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
const int N = 1e3 + 100;
const int B = 1024 * 4 + 5;
int n, k;
int dp[N][B];
int a[N], b[N];
int maxi = -INF;

void logic() {
    memset (dp, -INF, sizeof(dp));
    cin >> n >> k;
    k *= 1024;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - a[i]] + b[i]);
            }
        }
    }
    for (int i = 0; i <= k; ++i) {
        maxi = max(maxi, dp[n][i]);
    }
    cout << maxi;
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
