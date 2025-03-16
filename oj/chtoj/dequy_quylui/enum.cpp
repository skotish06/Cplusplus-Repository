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
#define task "ENUM"

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];

void ql(int i, int op, int cl) {
    if (op > n / 2 or cl > op) {
        return;
    }
    if (i > n) {
        for (int j = 1; j <= n; ++j) {
            if (a[j] == 0) cout << "(";
            else cout << ")";
        }
        cout << '\n';
    }
    else {
        for (int j = 0; j <= 1; ++j) {
            if (j == 0) {
                a[i] = j;
                ql(i + 1, op + 1, cl);
            }
            else {
                a[i] = j;
                ql(i + 1, op, cl + 1);
            }
        }
    }
}

void logic() {
    cin >> n;
    if (n & 1) return;
    ql(1, 0, 0);
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
