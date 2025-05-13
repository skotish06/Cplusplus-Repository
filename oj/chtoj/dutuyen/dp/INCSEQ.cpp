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
#define task "INCSEQ"

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
int dp[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j <= i - 1; ++j) {
            if (a[i] > a[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    cout << *max_element(dp + 1, dp + n + 1);
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
dp[i]: độ dài dãy đơn điệu tăng đến i
1, lấy 1 phần từ i
    dp[i] = 1;
2, ghép i vào dãy con tăng trước
    dp[1] 
    dp[2]
    ...
    dp[i]
*/
