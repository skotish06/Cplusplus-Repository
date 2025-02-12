#include <bits/stdc++.h>
#define int long long
#define MOD 123456789
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "DIVISOR"

using namespace std;
const int N = 3e6 + 9;
int n, a[N], k;
unordered_map<int, int> cnt;
unordered_set<int> s;
int ans = 1;

void pt(int x) {
    int i = 2;
    while (x > 1) {
        if (x % i == 0) {
            a[++k] = i;
            x /= i;
        } else i++;
    }
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pt(x);
    }
    for (int i = 1; i <= k; ++i) {
        s.insert(a[i]);
    }
    for (int i = 1; i <= k; ++i) {
        ++cnt[a[i]];
    }
    for (auto x : s) {
        ans = (ans * (cnt[x] + 1) % MOD) % MOD;
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
