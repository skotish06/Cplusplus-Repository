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
#define task "expression"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int a[N];
vector<char> c;
string res;
int pre[N];

void ql(int i, int sum, string s) {
    if (sum + pre[i] < k || sum - pre[i] > k) return;
    if (i > n) {
        if (sum == k) {
            cout << s;
            exit(0);
        } 
    }
    else {
        ql(i + 1, sum + a[i], s + '+');
        ql(i + 1, sum - a[i], s + '-');
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        pre[i] = pre[i + 1] + a[i];
    }
    ql(2, a[1], "");
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
