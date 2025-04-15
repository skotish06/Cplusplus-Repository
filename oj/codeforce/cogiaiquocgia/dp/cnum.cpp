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
const int N = 1e6 + 9;
int n;
int a[N];
int dp[N][3];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[1][1] = (a[1] != 1);
    dp[1][2] = (a[1] != 2);
    for (int i = 2; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + (a[i] != 1);
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (a[i] != 2);
    }
    cout << min(dp[n][1], dp[n][2]);
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
dp[i][j]: số cách biến đổi ít nhất để nhận được dãy tăng sau i thằng
sao cho a[i] = j
dp[3][1]
dp[4][2]
xét i: 
    a[i] = 1
        dp[i][1] = dp[i - 1][1] + (a[i] != 1);
    a[i] = 2
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (a[i] != 2);
*/