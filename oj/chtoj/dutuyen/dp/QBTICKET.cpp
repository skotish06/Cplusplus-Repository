#include <bits/stdc++.h>
using namespace std;

#define NAME "QBTICKET"
#define int long long
const int N = 1e5 + 5;
const int INF = 1e9;

int L1, L2, L3, C1, C2, C3;
int n, s, f;
int a[N], dp[N];

void solve()
{
    cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3;
    cin >> n >> s >> f;
    for (int i = 2; i <= n; i++)
        cin >> a[i];

    dp[s] = 0;
    for (int i = s + 1; i <= f; i++){
        dp[i] = LLONG_MAX;

        int t = lower_bound (a + s, a + n + 1, a[i] - L1) - a;
        int p = lower_bound (a + s, a + n + 1, a[i] - L2) - a;
        int z = lower_bound (a + s, a + n + 1, a[i] - L3) - a;

        if (t < i) dp[i] = min (dp[t] + C1, dp[i]);
        if (p < i) dp[i] = min (dp[p] + C2, dp[i]);
        if (z < i) dp[i] = min (dp[z] + C3, dp[i]);

    }

    cout << dp[f];
    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if(fopen(NAME ".inp", "r")){
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }

    solve ();
}
