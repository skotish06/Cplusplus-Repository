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
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
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
dp[i]: số cách xếp hàng cho i đứa thoả mãn
1, xét i nữ

1...i - 1 | nữ
dp[i - 1] | nữ

2, xét i nam, i - 1 nữ
1...i - 2 | nữ nam
dp[i - 2] | nữ nam

3, xét i nam, i - 1 nam, i - 2 nữ
1...i - 3 | nữ nam nam
dp[i - 3] | nữ nam nam

4, xét i nam, i - 1 nam, i - 2 nam
(không thoả mãn)

dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

*/