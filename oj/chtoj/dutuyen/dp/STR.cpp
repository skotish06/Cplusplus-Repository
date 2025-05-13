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
#define task "STR"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
string s;
int n;
int dp[N][2];

void logic() {
    cin >> s;
    n = s.size();
    s = ' ' + s;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'A') {
            dp[i][0] = dp[i - 1][0]; 
            dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
        }
        if (s[i] == 'B') {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
        }
    }
    cout << min(dp[n][0], dp[n][1] + 1);
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
