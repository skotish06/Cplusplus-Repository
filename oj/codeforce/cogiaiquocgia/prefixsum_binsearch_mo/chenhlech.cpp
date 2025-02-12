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
int a[N], pre[N];

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    while (k--) {
        int x, y; cin >> x >> y;
        int l = x, r = y;
        while (l <= r) {
            int mid =(l + r) / 2;

        }
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







// (1) (4 2 5) = 1 11
// (1 4) (2 5) = 5 7
// (1 4 2) (5) = 7 5
// (1 4 2 5) () = 12 0

// 5 1
// 3 1 4 2 5
// 2 5

// l = 2, r = 5
// 1 4 2 5
// 1 5 7 12
// mid = l + r >> 2
// pre[mid] = 5
// pre[r - mid - 1] = 11
// ans = 6
// s = s1 + s2

// s - s1 = s2
// min s2
// 1 5 7 12
// s = pre[r] - pre[l - 1] = 12
// find s1
// mid = l + r >> 2
// mid = 2
// s1 = pre[mid] - pre[l - 1] = 5
// s2 = 7


// 1 5 7 12
// s = 12
// mid = 2
// s1 = pre[mid] - pre[l - 1] = 5
// ans = min(ans, s - s1);
// r = mid - 1
// 









