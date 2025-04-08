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
const int N = 1e6 + 9;
int n, k;
int dp[N];
int pre[N];

void logic() {
    cin >> n >> k;
    dp[0] = 1;
    pre[0] = 1;
    for (int i = 1; i < k; ++i) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    for (int i = k; i <= n; ++i) {
        dp[i] = pre[i - 1];
        if (i - k - 1 >= 0) {
            dp[i] = ((dp[i] - pre[i - k - 1]) % MOD + MOD) % MOD;
        } 
        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    cout << dp[n] % MOD;
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


k
dp[i] = dp[i - 1] + dp[i - 2] + ... + dp[i - k];
dp[i] = pre[i - 1] - pre[i - k - 1];
pre[i] = pre[i - 1] + dp[i];

for (i -> n) {
    dp[i] = pre[i - 1];
    if (i - k - 1 >= 0) {
        dp[i] = dp[i] - pre[i - k - 1];
    } 
    pre[i] = pre[i - 1] + dp[i];
}




*/