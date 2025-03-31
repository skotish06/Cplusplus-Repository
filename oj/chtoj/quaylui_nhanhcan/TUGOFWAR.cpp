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
#define task "TUGOFWAR"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int f[N], a[N];
int sum, ans;
vector<int> p, pos;
int pre[N];
bool c[N];

void ql(int i, int sum) {
    if (ans == k) return;
    if (sum > k || sum + pre[n] - pre[i - 1] <= ans) return; 
    if (i > n) {
        if (sum > ans) {
            ans = sum;
            pos = p;
        }
    } else {
        ql(i + 1, sum);
        if (sum + a[i] <= k) {
            p.push_back(i);
            ql(i + 1, sum + a[i]);
            p.pop_back();
        }
    }
}

void logic() {
    memset(c, true, sizeof(c));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    k = pre[n] / 2;
    ql(1, 0);
    cout << pos.size() << ' ' << n - pos.size() << '\n';
    for (auto x : pos) {
        c[x] = false;
        cout << x << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; ++i) {
        if (c[i]) cout << i << ' ';
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
