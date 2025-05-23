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
const int N = 10;
int n, m;
char a[N][N];
int ans, xe;
bool c[N];

void ql(int i) {
    if (i > n) {
        ans = max(ans, xe);
    }
    else {
        for (int j = 0; j <= m; ++j) {
            if (j == 0) {
                ql(i + 1);
            }
            else if (a[i][j] != '*' and c[j] == false) {
                c[j] = true;
                ++xe;
                ql(i + 1);
                --xe;
                c[j] = false;
            }
        }
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    ql(1);
    cout << ans;
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
