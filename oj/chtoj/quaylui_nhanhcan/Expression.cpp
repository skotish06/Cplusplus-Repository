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
#define task "Expression"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int a[N];
vector<char> c;
int pre[N];
int sum;

void ql(int i) {
    if (i > n) {
        if (sum == k) {
            for (auto x : c) {
                cout << x;
            }
            exit(0);
        } 
    }
    else {
        if (sum + pre[n] - pre[i - 1] < k || sum - (pre[n] - pre[i - 1]) > k) {
            return;
        }
        c.push_back('+');
        sum += a[i];
        ql(i + 1);
        sum -= a[i];
        c.pop_back();
        c.push_back('-');
        sum -= a[i];
        ql(i + 1);
        sum += a[i];
        c.pop_back();
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i]; 
    }
    sum = a[1];
    ql(2);
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
