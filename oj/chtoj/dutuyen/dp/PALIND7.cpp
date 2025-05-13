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
#define task "PALIND7"
// dont copy my flow dude

using namespace std;
const int N = 5e3 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n;
int dp[N][N];
int a[N];
string s;

void trace(int i) {
    if (i == 0) return;
    for (int j = 1; j <= i; ++j) {
        if (dp[j][i] and a[i] == a[j - 1] + 1) {
            trace(j - 1);
            for (int k = j; k <= i; ++k) {
                cout << s[k];
            }
            cout << '\n';
            return;
        }
    }
}

void logic() {
    cin >> s;
    s = " " + s;
    n = s.size() - 1;
    for (int i = n; i >= 1; --i) {
        for (int j = i; j <= n; ++j) {
            if (i == j) dp[i][j] = 1;
            else if (i == j - 1) dp[i][j] = (s[i] == s[j]);
            else if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
        }
    }
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = inf;
        for (int j = 1; j <= i; ++j) {
            if (dp[j][i]) a[i] = min(a[i], a[j - 1] + 1);
        }
    }
    cout << a[n] << '\n';
    trace(n);
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

    // execute
    return 0;
}