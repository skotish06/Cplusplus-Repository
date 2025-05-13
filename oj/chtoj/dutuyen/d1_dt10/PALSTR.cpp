#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "PALSTR"

using namespace std;
const int N = 1e6 + 9;
int h, n;
string s;
int l, r;
bool dp[5005][5005];

void logic() {
    cin >> h;
    cin >> s;
    cin >> n;
    memset (dp, true, sizeof(dp));
    for (int i = 1; i < h; ++i) {
        dp[i][i + 1] = (s[i - 1] == s[i]);
    }
    for (int i = 1; i <= h; ++i) {
        for (int l = 1; l + i - 1 <= h; ++l) {
            int r = l + i - 1;
            dp[l][r] = (s[l - 1] == s[r - 1]) && dp[l + 1][r - 1];
        }
    }   
    while (n--) {
        cin >> l >> r;
        cout << (dp[l][r] ? "YES\n" : "NO\n");
    }
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
dp[l][r] == true nếu chuỗi s[l->r] là dãy plr
xét l r
    1 kí tự l == r
    2 kí tự s[i] == s[i + 1]
    dp[i][j] = (s[i - 1] == s[i])

dp[l][r] = (s[l - 1] == s[r - 1]) && dp[l + 1][r - 1];
*/
