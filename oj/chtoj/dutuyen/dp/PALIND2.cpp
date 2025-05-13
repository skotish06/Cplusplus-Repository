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
#define task "PALIND2"
// dont copy my flow dude

using namespace std;
const int N = 1e3 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;
string s;
int n, maxx, st, en;
bool dp[N][N];
int cnt;

void logic() {
    getline(cin, s);
    n = s.length();
    s = " " + s; 
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = true;
    }
    maxx = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            if (2 > maxx) {
                maxx = 2;
            }
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxx) {
                    maxx = len;
                }
            }
        }
    }
    cout << maxx << '\n';
    // s[i] -> s[i + maxx] {
    // cout << s[1] << ' ' << s[maxx] << '\n';
    for (int k = 1; k <= n - maxx + 1; ++k) {
        string sn = "";
        for (int i = k; i < k + maxx; ++i) {
            sn += s[i];
        }
        string ss = sn;
        reverse(ss.begin(), ss.end());
        if (sn == ss) {
            cnt++;
        }
    }
    cout << cnt;
    // nguuuuuuuuuuuuuuuuuuuuuuuuuuuu
    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

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