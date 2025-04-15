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
const int N = 1e3 + 9;
int n, S;
int a[N];
int dp[N][N];

void logic() {
    cin >> n >> S;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= S; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % MOD; 
            }
        }
    }
    cout << dp[n][S];
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
dp[i][j]: số lượng dãy con đến i có tổng bằng j
xét i: 
    không chọn i
        dp[i - 1][j]
    chọn i
        dp[i - 1][j - a[i]]
    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
-> dp[n][S]

*/