// #include <bits/stdc++.h>
#include <iostream>
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
int n, m;
char a[N][N];
int dp[N][N];

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        } 
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 and j == 1) {
                dp[i][j] = 1;
            }
            else if (a[i][j] != '#') {
                if (i - 1 >= 1 and a[i - 1][j] != '#')
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j - 1 >= 1 and a[i][j - 1] != '#')
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n][m];
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
dp[i][j]: số cách từ (1, 1) đi hợp lí để đến vị trí (i, j)

xét i j
    (i - 1, j) -> (i, j)
    dp[i][j] = dp[i - 1][j] + 1
    (i, j - 1) -> (i, j)
    dp[i][j] = dp[i][j - 1] + 1

    dp[i][j] = dp[i - 1][j]
               dp[i][j - 1] + 2
*/