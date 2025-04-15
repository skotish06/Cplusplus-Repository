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

void logic() {
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[max((int)0, i - k - 1)]) % MOD;
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
dp[i]: số cách xếp thoả mãn cho i thằng đầu

xét i:
    i là nữ
        1 ... i - 1 | nữ
        dp[i - 1] | nữ
    i là nam
        i - 1, i - 2, ..., i - k là nữ
        1 .. i - k - 1 | k nữ 1 nam
        dp[i - k - 1] | k nữ 1 nam

    -> dp[i] = dp[i - 1] + dp[i - k - 1]
-> dp[n]
*/