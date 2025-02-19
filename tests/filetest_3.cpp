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
int n, q, k, a[N], ans;
pair<int, int> c[N];

void sub1() {
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            c[++k].fi = a[i];
        }
        else {
            c[k].se = abs(q - c[k].fi);
        } 
    }
    cout << '\n';
    for (int i = 1; i <= k; ++i) {
        cout << c[i].fi << " " << c[i].se << "\n";
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j & 1) {
                ans += abs(c[i].fi - a[j]);
            }
            else {
                ans += abs(c[i].se - a[j]);
            }
        } 
    }
}
void logic() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sub1();
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
