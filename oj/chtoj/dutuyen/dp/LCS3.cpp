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
#define task "trace3"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e6 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, m;
int a[N], b[M];
int dp[2][M];

void trace(int i, int j) {
    if (i == 0 || j == 0) return;
    if (a[i] == b[j]) {
        trace(i - 1, j - 1);
        cout << a[i] << ' ';
    } else {
        if (dp[(i - 1) % 2][j] >= dp[i % 2][j - 1]) {
            trace(i - 1, j);
        } else {
            trace(i, j - 1);
        }
    }
}

void logic() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    for (int j = 1; j <= n; ++j) {
        cin >> b[j];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) dp[i % 2][j] = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            } else {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
    }
    trace(m, n);
    // cout << dp[m % 2][n] << '\n';
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
input:
9 9
1 2 7 3 4 8 5 6 9
1 2 3 4 5 6 7 8 9
output:
7
1 2 3 4 5 6 9
*/
/*
--/shouko\--
DRAFT:


------------
*/
