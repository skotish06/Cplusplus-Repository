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
#define task "SOCOLA"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int a[N];
int l, r;  

bool f(int x) {
    int cnt = 0;
    REP(i, n) {
        cnt += a[i] / x;
        if (cnt >= k) return true;
    }
    return cnt >= k;
}

void logic() {
    cin >> n >> k;
    REP(i, n) {
        cin >> a[i];
        r = max(r, a[i]);
    }
    l = 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (f(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
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
