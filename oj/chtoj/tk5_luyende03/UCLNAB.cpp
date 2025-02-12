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
#define task "UCLNAB"

using namespace std;
const int N = 1e6 + 9;
string l, r;
int ans;

// void sub1() {
//     for (int i = a; i <= b; ++i) {
//         ans = __gcd(ans, i);
//     }
//     cout << ans;
// }

void sub2() {
    if (l == r) cout << l;
    else cout << 1;
}

void logic() {
    cin >> l >> r;
    sub2();
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
