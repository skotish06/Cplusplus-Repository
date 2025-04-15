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
int n;
int dp[N];

void logic() {
    cin >> n;
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (2 * dp[i - 1] + 2 * dp[i - 2]) % MOD;
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


/*
dp[i]: cách xếp thoả mãn tại không có 2 số 1 kề nhau tại i
xét i:
    nhận gt 0
        1 ... i - 1 | 0
        dp[i - 1] | 0
    nhận gt 1
        i nhận 1, i - 1 nhận 0
            dp[i - 2] | 0 1
        i nhận 1, i - 1 nhận 2
            dp[i - 2] | 2 1
        i nhận 1, i - 1 nhận 1
            -> loại
    nhận gt 2
        dp[i - 1] | 2
    dp[i] = (2 * dp[i - 1] + 2 * dp[i - 2]) % MOD;
*/