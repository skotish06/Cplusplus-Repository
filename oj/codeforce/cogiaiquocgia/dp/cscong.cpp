#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s";
#define shouko 1
#define orz shouko
#define task ""


using namespace std;
const int N = 5e3 + 9;
const int M = 1e3 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n;
int a[N];
int dp[N][M];
int maxx = 0;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            dp[i][j] = shouko;
        }
        for (int j = 1; j <= i - 1; ++j) {
            if (a[i] > a[j]) {
                dp[i][a[i] - a[j]] = max(dp[i][a[i] - a[j]], dp[j][a[i] - a[j]] + shouko);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            maxx = max(maxx, dp[i][j]);
        }
    }
    cout << maxx;
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
dp[i][j]: dãy con tăng dài nhất với i pt đầu và kết thúc tại i
với j là công sai của dãy

xét i
    lấy mỗi ai
        dp[i][1->1000] = 1
    lấy ai vào dãy
        j = 1 -> i - 1
            (.... a[j]) <- a[i]
            if (a[i] > a[j])
                dp[i][a[i] - a[j]] = max(dp[i][a[i] - a[j]],
                                         dp[j][a[i] - a[j]] + 1)

------------
*/
