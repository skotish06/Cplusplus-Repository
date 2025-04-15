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
int n;
int a[N];
int sum;
int dp[N][N];
int maxx = -INF;
int pos;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= sum; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            for (int k = 1; k <= a[i]; ++k) {
                if (j - k >= 0)
                    dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    for (int i = 0; i <= sum; ++i) {
        if (maxx < dp[n][i]) {
            pos = i;
            maxx = dp[n][i];
        }
    }
    cout << pos;
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
-> tìm tổng lớn nhất

-> tìm tổng của mỗi lần role xúc xắc
dp[i][j]: tổng của i viên xúc bằng j

xét i: 
    1, i role ra 1
        i - 1 viên có tổng bằng 1
        dp[i - 1][j - 1]
    2, i role ra 2
        i - 1 viên có tổng bằng 2
        dp[i - 1][j - 2]
    ... 
    si, i role ra si
        i - si viên có tổng bằng si
        dp[i - 1][j - si]
*/
