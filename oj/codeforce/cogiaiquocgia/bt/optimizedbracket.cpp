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
const int N = 3e6 + 9;
int n;
int a[N];
pii c[N];
int cs, ans = LLONG_MAX;

void ql(int i, int op, int cl) {
    if (op > n / 2 or cl > op) {
        return;
    }
    if (i > n) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) cs += c[i].fi;
            else cs += c[i].se;
        }
        ans = min(ans, cs);
        cs = 0;
        // cout << cs;
    }
    else {
        a[i] = 0; ql(i + 1, op + 1, cl);
        a[i] = 1; ql(i + 1, op, cl + 1);
    }
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].fi >> c[i].se;
    }
    ql(1, 0, 0);
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

/*

4
2 1
1 4
5 3
2 2

(())

+2 +1 +3 +2



8 

*/