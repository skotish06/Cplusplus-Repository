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
#define task "CANDY"

using namespace std;
const int N = 55;
const int M = 1002;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, a[N], pre[N];
bool dp[N][M][M];
int res = inf;
int ans = inf;

void cal(int i, int x, int y, int z) {
    if (i > n) {
        int maxx = max(x, max(y, z));
        int minn = min(x, min(y, z));
        res = min(res, maxx - minn);
    }
    else {
        cal(i + 1, x + a[i], y, z);
        cal(i + 1, x, y + a[i], z);
        cal(i + 1, x, y,a[i] + z);
    }
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    if (n <= 10) {
        cal(1, 0, 0, 0);
        cout << res << '\n';
        return;
    }

    ms(dp, false);
    dp[0][0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int k1 = M - 1; k1 >= 0; --k1) {
            for (int k2 = M - 1; k2 >= 0; --k2) {
                int k3 = pre[i] - k1 - k2;
                if (k3 < 0) continue;
                if (k1 >= a[i] && dp[i - 1][k1 - a[i]][k2]) dp[i][k1][k2] = true;
                if (k2 >= a[i] && dp[i - 1][k1][k2 - a[i]]) dp[i][k1][k2] = true;
                if (k3 >= a[i] && dp[i - 1][k1][k2]) dp[i][k1][k2] = true;
            }
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!dp[n][i][j]) continue;
            int k = pre[n] - i - j;
            int maxx = max(i, max(j, k));
            int minn = min(i, min(j, k));
            ans = min(ans, maxx - minn);
        }
    }
    cout << ans << '\n';
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
*/