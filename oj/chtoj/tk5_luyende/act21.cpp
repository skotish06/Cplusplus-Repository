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
#define task "COVER1"

using namespace std;

const int N = 1e6 + 9;
int n;
pii a[N];

bool cmp(pii x, pii y) {
    return x.se < y.se;
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    cout << '\n';
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        cout << a[i].fi << ' ' << a[i].se << '\n';
    }
}

/*
0 6
l = 0, r = 6
1 3
3 7
6 8
7 9
*/

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