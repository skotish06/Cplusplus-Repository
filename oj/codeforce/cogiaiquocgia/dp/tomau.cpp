#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define task ""

using namespace std;
const int N = 1e6 + 9;
int n;
int c[N][3];
int dp[N][3];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i][0] >> c[i][1] >> c[i][2]; 
    }

    dp[1][0] = c[1][0];
    dp[1][1] = c[1][1];
    dp[1][2] = c[1][2];

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + c[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + c[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + c[i][2];
    }

    int result = min({dp[n][0], dp[n][1], dp[n][2]});
    cout << result << '\n';
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