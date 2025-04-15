// #include <bits/stdc++.h>
#include <iostream>
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
const int N = 5e2 + 9;
int n, m;
int a[N][N];
int dp[N][N];
int maxx = -INF;

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = a[i][1];
    }
    for (int j = 2; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = dp[i][j-1] + a[i][j];
            if (i > 1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
            }
            if (i < n) {
                dp[i][j] = max(dp[i][j], dp[i+1][j-1] + a[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        maxx = max(maxx, dp[i][m]);
    }
    cout << maxx;
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


/*
dp[i][j]: đường đi lớn nhất đến i j
xét i j
    (i - 1, j - 1) -> (i, j)
        dp[i - 1][j - 1] + a[i][j]
    (i, j - 1) -> (i, j)
        dp[i][j - 1] + a[i][j]
    (i + 1, j - 1) -> (i, j)
        dp[i + 1][j - 1] + a[i][j]
*/