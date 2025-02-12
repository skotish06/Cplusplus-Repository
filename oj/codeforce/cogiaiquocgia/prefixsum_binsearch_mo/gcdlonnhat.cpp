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
#define task ""

using namespace std;
const int N = 1e6 + 9;
int n, q;
int a[N];
int pre[N];
int ans;
int suf[N];

void logic() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = __gcd(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = __gcd(suf[i + 1], a[i]);
    }
    // 
    for (int i = 1; i <= n; ++i) {
        int j = i + q - 1;
        ans = max(ans, __gcd(pre[i - 1], suf[i + q]));
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
