#include <bits/stdc++.h>
#define int long long
#define MOD 1000000
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
int a[N];
int S = 0;
int dp[N][N];
int ans = -INF;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        S += a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= S; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]]); 
            }
        }
    }
    for (int i = 0; i <= S; ++i) {
        if (dp[n][i] == 1) {
            ans = max(ans, abs(i * (S - i)));
        } 
    }
    cout << ans;
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
dp[i][j] = 1 nếu i số đầu tạo được dãy con có tổng bằng j
dp[i][j] = 0 nếu i số đầu không tạo được dãy con có tổng bằng j

xét i
    không chọn i vào dãy
        i - 1 viên kẹo trước tạo thành tổng j

    chọn i vào dãy

*/