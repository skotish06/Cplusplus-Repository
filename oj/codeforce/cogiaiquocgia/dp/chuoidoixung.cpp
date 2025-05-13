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
#define task "PALIND4"

using namespace std;
const int N = 2e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

string s;
int dp[N][N];
int n;

void trace(int l, int r) {
    if (l > r) return;
    if (l == r) {
        cout << s[l];
        return;
    }
    if (s[l] == s[r] and dp[l][r] == dp[l + 1][r - 1] + 2) {
        cout << s[l];
        trace(l + 1, r - 1);
        cout << s[r];
    }
    else if (dp[l][r] == dp[l + 1][r]) {
        trace(l + 1, r);
    }
    else {
        trace(l, r - 1);
    }
}

void logic() {
    cin >> s;
    s = " " + s;
    n = s.size() - 1;

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int r = 1; r <= n; ++r) {
        for (int l = r - 1; l >= 1; --l) {
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1] + 2;
            }
            else {
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }

    // cout << dp[1][n] << '\n';
    trace(1, n);
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

dp[l][r]: là độ dài chuỗi đối xứng dài nhất trong đoạn l r
xét s[l], s[r]
    nếu s[l] == s[r]
        dp[l + 1][r - 1] + 2
    nếu s[l] != s[r]
        max(dp[l + 1][r], dp[l][r - 1])
    -> dp[1][n]
------------
*/
