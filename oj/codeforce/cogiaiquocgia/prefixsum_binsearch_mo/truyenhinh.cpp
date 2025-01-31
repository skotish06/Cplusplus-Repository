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
int n, res;
pair<int, int> a[N];

bool cmp(pii x, pii y) {
    return x.se < y.se;
}

void logic() {
    cin >> n;
    REP(i, n) {
        cin >> a[i].fi >> a[i].se;
    }
    sort (a + 1, a + n + 1, cmp);

    REP(i, n) {
        int l = 1, r = i - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (a[mid].second > a[i].first) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        } 
        if (ans != -1) {
            res += (i - ans);
        }
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
