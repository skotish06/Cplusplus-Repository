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
#define task "LIQ"

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
int dp[N];
int maxi = LLONG_MIN;
int pos;

void trace(int i) {
    int pos = 0;
    for (int j = 1; j <= i - 1; ++j) {
        if (a[i] > a[j] && dp[i] == dp[j] + 1) {
            pos = j;
            // break;
        }
    } 
    if (pos != 0) {
        trace(pos);
    }
    cout << i << ' ';
} 

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j <= i - 1; ++j) {
            if (a[i] > a[j] and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (maxi < dp[i]) {
            maxi = dp[i];
            pos = i;
        }
    }
    cout << maxi << '\n';
    trace(pos);
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
