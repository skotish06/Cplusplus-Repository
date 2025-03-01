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
#define task "cau1"

using namespace std;
const int N = 1e6 + 9;
int n, m, ans;

void logic() {
    cin >> n >> m;
    if (m % n != 0) {
        cout << -1;
        return;
    }
    
    for (int i = 1; i * i <= m / n; ++i) {
        if ((m / n) % i == 0) {
            int a = n * i;
            int b = n * ((m / n) / i);
            if (__gcd(a, b) == n) {
                ans = a + b;
            }
        }
    }
    cout << ans;
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
