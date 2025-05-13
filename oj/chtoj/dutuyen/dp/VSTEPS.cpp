#include <bits/stdc++.h>
#define int long long
#define MOD 14062008
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "VSTEPS"

using namespace std;
const int N = 1e6 + 9;

int n, k, a[N], dp[N];
bool fix[N];

void logic(){
    cin >> n >> k;
    for (int i = 1; i <= k; ++i){
        cin >> a[i];
        fix[a[i]] = true;
    }
    dp[1] = 1;
    if (fix[2] == true) dp[2] = 0;
    else dp[2] = 1;
    for (int i = 3; i <= n; ++i){
        if (!fix[i])
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n];
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
