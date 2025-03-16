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
int n, k;
int a[N];

void init() {
    iota(a, a + k, 0);
}

bool nextgen() {
    int i = k - 1;
    while (i >= 0 and a[i] == n - k + i) {
        --i;
    }
    if (i < 0) return false;
    iota(a + i, a + k, a[i] + 1);
    return true;
}

void logic() {
    cin >> n >> k;
    init();
    do {
        for (int i = 0; i < k; ++i) {
            cout << a[i] + 1 << ' ';
        }
        cout << '\n';
    }
    while (nextgen());
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
