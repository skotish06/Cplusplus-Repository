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
int cnt, ans;
int a[N], pre[N];

void logic() {
    cin >> n >> k;
    REP(i, n) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    REP(j, n) {
        int l = 1, r = j, res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (pre[mid - 1] >= pre[j] - k) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (res != -1) {
            ans += (j - res + 1);
        }
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
