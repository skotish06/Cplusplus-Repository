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
int n;
int h[N], f[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    f[1] = 0;
    f[2] = abs(h[1] - h[2]);
    for (int i = 3; i <= n; ++i) {
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]),
                   f[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << f[n];
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
