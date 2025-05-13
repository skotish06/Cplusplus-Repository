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
#define task ""

using namespace std;
const int N = 2e2 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, x;
int a[N], b[N];
int dp[N][N];

void logic() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = b[i]; 
        for (int k = 2; k <= x; ++k) {
            dp[i][k] = -inf;
            for (int j = 1; j < i; ++j) {
                if (a[i] != a[j]) {
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + b[i]);
                }
            }
        }
    }

    int maxx = -inf;
    for (int i = 1; i <= n; ++i) {
        maxx = max(maxx, dp[i][x]);
    }

    if (maxx < 0) cout << -1 << '\n';
    else cout << maxx << '\n';

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

    int q; cin >> q;
    while (q--) {
        logic();
    }

    return 0;
}

/*
--/shouko\--
DRAFT:

Fix:
- dp[i][1] = b[i]
- Khởi tạo dp[i][k] = -inf
- Check maxx == -inf thì in -1

------------
*/