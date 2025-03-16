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
int f[N];
int a, b;

void seg_sieve(int l, int r) {
    int i, j;
    for (int i = 2; i * i <= r; ++i) {
        for (int j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
            ++f[j - l];
        }
    }
}

void logic() {
    cin >> a >> b;
    seg_sieve(a, b);
    for (int i = max(2LL, a); i <= b; ++i) {
        if (f[i - a] == 0) cout << i << ' ';
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
