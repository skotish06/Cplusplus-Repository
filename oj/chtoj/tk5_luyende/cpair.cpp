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
#define task "CPAIR"

using namespace std;
const int N = 1e6 + 9;
int n, l, r, a[N], pre[N], ans;

void sub1() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (abs(pre[j] - pre[i - 1]) >= l and abs(pre[j] - pre[i - 1]) <= r) {
                ++ans;
            }
        }
    }
    cout << ans;
}

void sub2() {
    // i <= j and L <= |ai + ai+1 + ... + aj| <= R
    // |ai + ai+1 + ... + aj| = |pre[aj] - pre[ai-1]|


}

void logic() {
    cin >> n >> l >> r;
    REP(i, n) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    sub1();
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
