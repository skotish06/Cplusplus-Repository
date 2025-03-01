#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a, n) (a) + 1, (a) + (n) + 1
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task ""

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N], p[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = a[i];
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        int it1 = lower_bound(a + 1, a + n + 1, p[i]) - a;
        int it2 = upper_bound(a + 1, a + n + 1, p[i]) - a - 1;
        cout << it1 << ' ' << it2 << '\n';
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
