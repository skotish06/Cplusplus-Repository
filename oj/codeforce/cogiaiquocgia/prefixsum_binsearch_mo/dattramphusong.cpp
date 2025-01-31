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
const int N = 1e6 + 9;
int n, k;
int pre[N];
int ans, res;
pair<int, int> a[N];

void logic() {
    cin >> n >> k;
    REP(i, n) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    REP(i, n) {
        pre[i] = pre[i - 1] + a[i].se;
    }
    REP(i, n) {
        int l = i, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid].fi <= a[i].fi + 2 * k) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        res = max(res, pre[ans] - pre[i - 1]);
    }    
    cout << res;
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
