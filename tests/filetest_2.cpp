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
const int N = 25;
int n, m, w;
int a[N][N], Max = -1, mx[N];
bool stop;

void ql(int i, int last, int sum) {
    if (stop) return;
    if (sum + mx[i] < Max || sum > w) return;
    if (i > n) {
        Max = max(Max, sum);
        if (Max == w) {
            stop = 1;
        }
        return;
    }
    for (int j = m; j >= 1; j--) {
        if (a[i][j] < last) break;
        if (sum + a[i][j] * (n - i + 1) > w) continue;
        ql(i + 1, a[i][j], sum + a[i][j]);
    }
}

void logic() {
    cin >> m >> n >> w;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[j][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i] + 1, a[i] + 1 + m);
    }
    for (int i = n; i >= 1; i--) {
        mx[i] = mx[i + 1] + a[i][m];
    }
    ql(1, 0, 0);
    cout << Max;
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
