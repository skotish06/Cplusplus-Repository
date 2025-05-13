#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task "BOARD"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, m;
int a[N][N];
int dp[N][N];
int maxx = LLONG_MIN;
int st, en;

void trace(int i, int j) {
    if (j == 1) {
        cout << i << ' ' << j << '\n';
        return;
    }
    if (dp[i][j] == dp[i][j-1] + a[i][j]) {
        trace(i, j-1);
    } else if (i > 1 && dp[i][j] == dp[i-1][j-1] + a[i][j]) {
        trace(i-1, j-1);
    } else if (i < n && dp[i][j] == dp[i+1][j-1] + a[i][j]) {
        trace(i+1, j-1);
    }
    cout << i << ' ' << j << '\n';
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = a[i][1];
    }
    for (int j = 2; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = dp[i][j-1] + a[i][j];
            if (i > 1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
            }
            if (i < n) {
                dp[i][j] = max(dp[i][j], dp[i+1][j-1] + a[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dp[i][m] > maxx) {
            st = i, en = m;
            maxx = dp[i][m];
        }
    }
    cout << maxx << '\n';
    trace(st, en);
    // execute;
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
--/shouko\--
DRAFT:


------------
*/
