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
#define task "FLOAT"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int a[N];
int cnt;
int sum;

void logic() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int l = 0;
	for (int r = 1; r <= n; ++r) {
		sum += a[r];
		while (sum >= k) {
			if (sum == k) ++cnt;
			sum -= a[++l];
		}
	}
	cout << cnt;
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
