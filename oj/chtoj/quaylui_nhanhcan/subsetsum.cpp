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
#define task "SUBSETSUM"

using namespace std;
const int N = 1e6 + 9;
int n, k, a[N];
vector<int> c;
int pre[N];

bool ql(int i, int sum) {
    if (sum > k) return false;
    if (sum == k) {
        cout << "YES\n";
        for (int x : c) cout << x << ' ';
        cout << '\n';
        return true;
    }
    if (i > n || sum + pre[n] - pre[i - 1] < k) return false; 
    else {
        if (ql(i + 1, sum)) return true;
        c.push_back(i);
        if (ql(i + 1, sum + a[i])) return true;
        c.pop_back(); 
        return false;
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i]; 
    }
    if (!ql(1, 0)) cout << "NO\n";
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
