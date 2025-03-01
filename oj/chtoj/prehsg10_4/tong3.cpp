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
#define task "TSUM"

using namespace std;
const int N = 2e6 + 9;
int n;
int a[N];
int cnt;
int cntt[4 * N]; 
int ans;

void sub1() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                for (int l = k + 1; l <= n; ++l) {
                    if (a[i] + a[j] == a[l] - a[k]) {
                        cnt = (cnt + 1) % MOD;
                    }
                }
            }
        }
    }
    cout << cnt % MOD;
}

void sub23() {
    memset(cntt, 0, sizeof(cntt)); 
    ans = 0; 
    int x = 2e6 + 5;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int y = (a[j] - a[i] + x);
            if (y >= 0 and y < 4 * x) {
                ans = (ans + cntt[y]) % MOD;
            }
        }
        for (int k = 1; k < i; ++k) {
            int sum = a[i] + a[k] + x;
            if (sum >= 0 and sum < 4 * x) {
                cntt[sum]++;
            }
        }
    }

    cout << ans % MOD;
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n <= 10) sub1();
    else sub23();
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