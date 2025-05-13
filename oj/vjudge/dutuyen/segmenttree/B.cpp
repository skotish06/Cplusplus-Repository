#include <bits/stdc++.h>
// #include <iostream>
// #include <set>
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
#define task "cardgame"

using namespace std;
const int N = 5e5 + 5;
int n;
int a[N], l[N], r[N];
bool f[N];
set<int> s, t;   
int ans;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[a[i]] = true;
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (!f[i]) {
            s.insert(i);
            t.insert(-i); 
        }
    }
    for (int i = 1; i <= n; ++i) {
        auto it = s.lower_bound(a[i]);
        if (it != s.end()) {
            l[i] = l[i - 1] + 1;
            s.erase(it);
        } else {
            l[i] = l[i - 1];
        }
    }
    for (int i = n; i >= 1; --i) {
        auto it = t.lower_bound(-a[i]);
        if (it != t.end()) {
            r[i] = r[i + 1] + 1;
            t.erase(it);
        } else {
            r[i] = r[i + 1];
        }
    }
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, l[i] + r[i + 1]);
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".in", "r")) {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();

    return 0;
}