// #include <iostream>
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
#define task "WSEQ0"

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
pair<int, int> dp[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[1].fi = a[1];
    dp[1].se = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i].fi = min(dp[i - 1].fi, dp[i - 1].se + a[i]);
        dp[i].se = min(dp[i - 1].se, max(dp[i - 1].fi, dp[i - 1].se) - a[i]);
    }
    cout << min(dp[n].fi, dp[n].se);
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
