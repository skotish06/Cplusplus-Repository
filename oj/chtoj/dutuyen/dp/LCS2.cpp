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
#define task "LCS2"

using namespace std;
const int N = 1e3 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

string s;
int n, m;
int x[N];
vector<int> y;
vector<vector<int>> dp;
vector<vector<int>> g;

void minimize(int &a, int b) {
    if (a == -1 || a > b) a = b;
}

void logic() {
    getline(cin, s);
    m = s.size();
    for (int i = 1; i <= m; ++i) {
        x[i] = s[i - 1] - 'A';
    }
    getline(cin, s);
    n = s.size();
    y.resize(n + 2);
    g.assign(n + 2, vector<int>(26, inf));
    for (int i = 1; i <= n; ++i) {
        y[i] = s[i - 1] - 'A';
    }

    for (int c = 0; c < 26; ++c) {
        g[n + 1][c] = inf;
    }
    for (int i = n; i >= 1; --i) {
        for (int c = 0; c < 26; ++c) {
            g[i][c] = g[i + 1][c];
        }
        g[i][y[i]] = i;
    }

    dp.assign(m + 2, vector<int>(m + 2, inf));
    for (int i = 0; i <= m; ++i) dp[i][0] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int k = 1; k <= i; ++k) {
            dp[i][k] = dp[i - 1][k];
            if (dp[i - 1][k - 1] < inf) {
                int pos = g[dp[i - 1][k - 1] + 1][x[i]];
                if (pos < inf) {
                    minimize(dp[i][k], pos);
                }
            }
        }
    }

    int len = m;
    while (len > 0 && dp[m][len] == inf) {
        len--;
    }

    string res;
    int i = m, k = len;
    while (k > 0) {
        if (dp[i][k] != dp[i - 1][k]) {
            res += char(x[i] + 'A');
            --k;
        }
        --i;
    }

    reverse(res.begin(), res.end());
    cout << res;
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