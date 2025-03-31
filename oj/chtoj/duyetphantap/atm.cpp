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
#define task "ATM"

using namespace std;
const int N = 1e6 + 9;

int n, m, ans;
int a[N];
vector<int> v, h;

void ql1(int i, int sum, int lim) {
    if (i > lim) {
        v.push_back(sum);
    }
    else {
        ql1(i + 1, sum, lim);
        ql1(i + 1, sum + a[i], lim);
    }
}

void ql2(int i, int sum, int lim) {
    if (i > lim) {
        h.push_back(sum);
    }
    else {
        ql2(i + 1, sum, lim);
        ql2(i + 1, sum + a[i], lim);
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ql1(1, 0, (int)n / 2);
    ql2((int)n /2 + 1, 0, n);
    sort(h.begin(), h.end());
    for (auto x : v) {
        ans += upper_bound(h.begin(), h.end(), m - x) - lower_bound(h.begin(), h.end(), m - x);
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
