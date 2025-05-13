#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define task "DUMBBELL"
using namespace std;
const int N = 15;         
const int S = 10005;      
int n, w;
int p[N];
int dp[S];
int res = INF;
int sum;
int wei[6] = {1, 2, 5, 10, 15, 20};

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    cin >> w;
    for (int r = 0; r <= n; ++r) {
        sum = 0;
        for (int i = 1; i <= n - r; ++i) {
            sum += p[i];
        }
        if (sum > w) continue;
        for (int i = 0; i <= w - sum; ++i) {
            dp[i] = INF;
        }
        dp[0] = 0;
        for (int i = 1; i <= w - sum; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (i >= wei[j]) {
                    dp[i] = min(dp[i], dp[i - wei[j]] + 1);
                }
            }
        }
        if (w - sum >= 0) {
            res = min(res, r + dp[w - sum]);  
        }
    }
    cout << res << '\n';
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