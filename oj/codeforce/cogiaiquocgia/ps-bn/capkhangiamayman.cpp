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
int n, p;
int a[N], pre[N];

void logic() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    pre[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        pre[i] = min(pre[i - 1], a[i]);
    }
    int res = 0, pos1 = 0, pos2 = 0;
    for (int j = 1; j <= n; ++j) {
        int l = 1, r = j - 1, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (pre[mid] <= (a[j] - p)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        if (ans != 0) {
            if (res < j - ans) {
                res = j - ans;
                pos1 = ans;
                pos2 = j;
            }
        }
    }
    if (res == 0) {
        cout << 0;
    }
    else {
        cout << pos1 << ' ' << pos2;
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