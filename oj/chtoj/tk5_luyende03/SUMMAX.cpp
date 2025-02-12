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
#define task "SUMMAX"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int a[N];
int pre[N];
int sum_max = LLONG_MIN;
int maxx[N];
int cmax = LLONG_MIN;

void sub1() {
    for (int i = 1; i <= n; ++i) {
        int l = i, r = i + k - 1;
        while (l <= r) {
            sum_max = max(sum_max, pre[r] - pre[l - 1]);
            r--;
        }
    }
    cout << sum_max;
}

void sub2() {
    for (int i = 1; i <= n; ++i) {
        maxx[i] = pre[i] - pre[max(0LL, i - k)];
        if (i > 1) {
            maxx[i] = max(maxx[i], maxx[i - 1] + a[i]);
        }
        cmax = max(cmax, maxx[i]);
    }

    cout << cmax << '\n';
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    if (n <= 1e3) sub1();
    else sub2();

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