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
int n, x, q;
int a[N];

void logic() {
    cin >> n;
    REP(i, n) {
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        cin >> x;
        int l = lower_bound(a + 1, a + n + 1, x) - a;
        int r = upper_bound(a + 1, a + n + 1, x) - a - 1;
        if (binary_search(a + 1, a + n + 1, x)) {
            cout << l << ' ' << r << '\n';
        }
        else {
            cout << "-1 -1" << '\n';
        }
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
