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
#define task "MXS"

using namespace std;
const int N = 1e6 + 9;
int n, a[N], lmax[N], rmax[N];
int res = LLONG_MIN;

void logic() {
    cin >> n;
	if (n < 2) {
		cout << 0;
	}
	else {
		FOR(i, 1, n) {
			cin >> a[i];
		}
		lmax[1] = a[1];
		int sum = a[1];
		FOR(i, 2, n) {
			sum = max(a[i], sum + a[i]);
			lmax[i] = max(lmax[i - 1], sum);
		}
		rmax[n] = a[n], sum = a[n];
		for (int i = n - 1; i >= 1; i--) {
			sum = max(a[i], sum + a[i]);
			rmax[i] = max(rmax[i + 1], sum);
		}
		FOR(i, 1, n - 1) res = max(res, lmax[i] + rmax[i + 1]);
		cout << res << '\n';
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