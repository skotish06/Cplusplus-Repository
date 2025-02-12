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
#define task "SDB"

using namespace std;
const int N = 1e6 + 9;
int n, a[N], t = 1, f[N];
int q;

void sieve(){
    fill (f + 1, f + N + 1, 2);
	for (int i = 2; i <= sqrt(N); i++){
		f[i * i]--;
		for (int j = i; i * j <= N; j++){
			f[i * j] += 2;
		}
	}

}

void logic() {
    sieve();
	for (int i = 1; i <= N; i++){
        if (i % 3 == 0 and f[i] == 9)
            a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1];
	}
    cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
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
