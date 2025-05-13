#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d, x) memset(d, x, sizeof(d))
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define task "LCS1"

using namespace std;
const int N = 1e3 + 9;
const int inf = 1e18;

string str1, str2;
int dp[N][N];

void trace(int i, int j) {
    int p1 = 0, p2 = 0;
    if (i == 0 || j == 0) return;
    if (str1[i - 1] == str2[j - 1]) {
        p1 = i - 1;
        p2 = j - 1;
    } else if (dp[i - 1][j] >= dp[i][j - 1]) {
        p1 = i - 1;
        p2 = j;
    } else {
        p1 = i;
        p2 = j - 1;
    }
    if (p1 != i || p2 != j) {
        trace(p1, p2);
    }
    if (str1[i - 1] == str2[j - 1]) {
        cout << str1[i - 1];
    }
}

void logic() {
    cin >> str1 >> str2;
    int m = str1.size(), n = str2.size();
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    trace(m, n);
    cout << '\n';
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