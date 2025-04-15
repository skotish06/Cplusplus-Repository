#include <bits/stdc++.h>
// #include <iostream>
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
const int N = 1e3 + 9;
int n;
int a[N][N];
int dp[N][N];
int minn = INF;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = a[1][i];
    }
    for (int i = 2; i <= n; ++i) {
        
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j] + a[i][j];
            if (j - 1 >= 1) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            }
            if (j + 1 <= n) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        minn = min(minn, dp[n][i]);
    }
    cout << minn;
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
dp[i][j]: là tổng đường đi ngắn nhất để đến được ô (i, j)
*/
