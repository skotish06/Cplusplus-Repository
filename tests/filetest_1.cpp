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
#define task "SUBSETSUM3"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int f[N], a[N];
int sum, ans;
vector<int> p, pos;

void ql(int i) {
    if (ans == k - 1) return;
    if (i > n) {
        if (sum > ans) {
            ans = sum;
            pos = p;
        }
    } else {
        for (int j = 0; j <= 1; ++j) {
            if (sum >= k) return; 
            if (j == 0) {
                ql(i + 1);
            }
            if (j == 1 and sum + a[i] < k) {
                sum += a[i];
                p.push_back(i);
                ql(i + 1);
                p.pop_back();
                sum -= a[i];
            }
        }
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ql(1);
    cout << ans << '\n';
    for (auto x : pos) {
        cout << x << ' ';
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
