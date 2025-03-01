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
#define task "LMINMAX"

using namespace std;
const int N = 1e6 + 9;
int maxx = LLONG_MIN, minn = LLONG_MAX;
int ans = LLONG_MIN;
int n, k;
int a[N];
deque<int> mnD, mxD;

void sub1() {
    for (int i = 1; i <= n; ++i) {
        maxx = LLONG_MIN, minn = LLONG_MAX;
        for (int j = i; j <= n; ++j) {
            maxx = max(maxx, a[j]), minn = min(minn, a[j]);
            if (maxx - minn <= k) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans;
}

void sub2() {
    int l = 1;
    for (int r = 1; r <= n; ++r) {
        while (!mnD.empty() and mnD.back() > a[r]) mnD.pop_back();
        while (!mxD.empty() and mxD.back() < a[r]) mxD.pop_back();
        mxD.push_back(a[r]);
        mnD.push_back(a[r]);
        while (mxD.front() - mnD.front() > k) {
            if (a[l] == mxD.front()) mxD.pop_front();
            if (a[l] == mnD.front()) mnD.pop_front();
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
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
