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
int a[N], res[N];
int n;
int l[N], r[N];
stack<int> le, ri;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        res[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        while (!le.empty() && a[le.top()] >= a[i]) {
            le.pop();
        }
        while (!ri.empty() && a[ri.top()] >= a[n - i + 1]) {
            ri.pop();
        }
        if (!le.empty()) {
            l[i] = le.top();
        } else {
            l[i] = 0;
        }
        if (!ri.empty()) {
            r[n - i + 1] = ri.top();
        } else {
            r[n - i + 1] = n + 1;
        }
        le.push(i);
        ri.push(n - i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        int len = r[i] - l[i] - 1;
        res[len] = max(res[len], a[i]);
    }
    for (int i = n - 1; i >= 1; --i) {
        res[i] = max(res[i], res[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << ' ';
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
