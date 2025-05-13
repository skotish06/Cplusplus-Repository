#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define task ""

using namespace std;

const int N = 1e6 + 9;
int dp[N], x, n;
vector<int> ds[N];

void sieve() {
    for (int i = 2; i <= N; ++i)
        for (int j = i * 2; j <= N; j += i)
            ds[j].push_back(i); 
}

void logic() {
    sieve();
    dp[0] = 0;
    for (int n = 1; n <= N; ++n) {
        dp[n] = dp[n - 1] + 1; 
        for (int i : ds[n]) {
            if (i != 1 && n / i != 1) {
                dp[n] = min(dp[n], dp[max(i, n / i)] + 1); 
            }
        }
    }
    cin >> n;
    while (n--) {
        cin >> x;
        cout << dp[x] << '\n';
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

2123
2321
2132
3221