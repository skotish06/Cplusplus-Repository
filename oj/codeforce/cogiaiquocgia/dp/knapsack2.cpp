#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define task ""

using namespace std;
const int N = 1e2 + 9;
const int M = 1e4 + 5;
int dp[N][M];
int w[N], v[N], a[N];
int n, k;
int maxx = -INF;

void logic() {
    memset (dp, -INF, sizeof(dp));
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i] >> a[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int id = a[i]; id >= 1; --id) {
                if (j - id * w[i] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - id * w[i]] + id * v[i]);
                }
            }
        }
    }
    for (int i = 0; i <= k; ++i) {
        maxx = max(maxx, dp[n][i]);
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
dp[i][j]: tổng giá trị lớn nhất sau i thằng sao cho tổng trọng lượng
chính xác bằng j
xét i
    không chọn i
        dp[i - 1][j]
    chọn i
        dp[i][j - (1->a[i]) * w[i]] + (1->a[i]) * v[i]
*/