#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define task ""

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
int n;
int a[N];
int dp[N][2];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[1][1] = -a[1];
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i][1] = max(dp[i - 1][0] - a[i], dp[i - 1][1]);
        dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
    }
    cout << dp[n][0];
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
dp[i][j]: tổng lợi nhuật lớn nhất sao n ngày giao dịch
với j nếu j = 0 sau i ngày thì k còn bc
      nếu j = 1 sau i ngày còn vẫn còn bc
-> dp[n]

xét i
    mua 
        dp[i][1] = dp[i - 1][0] - a[i]
    bán
        dp[i][0] = dp[i - 1][1] + a[i]
    không làm gì
        dp[i][0] = dp[i - 1][0]
        dp[i][1] = dp[i - 1][1]
    dp[i][1] = max(dp[i - 1][0] - a[i].
                   dp[i - 1][1])
    dp[i][0] = max(dp[i - 1][1] + a[i].
                   dp[i - 1][1])
*/