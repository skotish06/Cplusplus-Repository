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
#define task "NQUEENS"

using namespace std;
const int N = 1e6 + 9;
int n;

void logic() {
    cin >> n;
    if (n == 2 or n == 3) {
        cout << "NO";
        return;
    }
    cout << "YES";
    cout << '\n';
    int j = 1;
    int m = (n % 2 == 0) ? n / 2 : n / 2 + 1;
    for (int i = 1; i <= m; ++i) {
        cout << i << ' ' << j << '\n';
        j += 2;
    }
    j = 2;
    for (int i = m + 1; i <= n; ++i) {
        cout << i << ' ' << j << '\n';
        j += 2;
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
