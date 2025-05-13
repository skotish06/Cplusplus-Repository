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
#define task "LEXLCS"


using namespace std;
const int N = 2e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
string s1, s2;
int n, m;
vector<vector<int>> dp(N, vector<int>(N, 0));
string v = "";
string v1, v2;

void trace(int i, int j) {
    int p1 = 0, p2 = 0;
    if (i == 0 || j == 0) return;
    if (s1[i - 1] == s2[j - 1]) {
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
    if (s1[i - 1] == s2[j - 1]) {
        // cout << s1[i - 1];
        v += s1[i - 1];
    }
}

void logic() {
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int m = s1.size(), n = s2.size();
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    trace(m, n);
    reverse(v.begin(), v.end());
    // cout << v << '\n';
    v1 = v;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    v = "";
    trace(m, n);
    v2 = v;
    cout << (v1 > v2 ? v1 : v2) << '\n';
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = m, j = n;
    string result = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result += s1[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1]) {
            result += s1[i - 1];
            i--;
        }
        else {
            result += s2[j - 1];
            j--;
        }
    }
    while (i > 0) {
        result += s1[i - 1];
        i--;
    }
    while (j > 0) {
        result += s2[j - 1];
        j--;
    }
    reverse(result.begin(), result.end());
    cout << result << '\n';
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
