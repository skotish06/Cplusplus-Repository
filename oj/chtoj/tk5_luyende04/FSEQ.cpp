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
#define task "FSEQ"

using namespace std;
const int N = 1e6 + 9;
int n, a[N], pre[N], gmax = LLONG_MIN;
int smax = LLONG_MIN;
int maxx = LLONG_MIN;
int mp[N];
int an;

void f() {
    for (int i = 1; i <= n; ++i) {
        maxx = max(maxx, mp[a[i]]);
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (mp[a[i]] == maxx) {
            cout << '\n' << a[i];
            break;
        }
    }
}

void sub1() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((pre[j] - pre[i - 1]) / (j - i + 1) >= gmax) {
                gmax = (pre[j] - pre[i - 1]) / (j - i + 1);
            }
        }
    }
    cout << gmax;
}

void sub2() {
     // (ai + ai+1 + ... + aj) / (j - i + 1) >= gmax
     // = (pre[j] - pre[i - 1]) / (j - i + 1) >= gmax
     // = pre[j] - pre[i - 1] >= gmax * (j - i + 1)
     // = pre[i - 1] <= pre[j] - gmax * (j - i + 1)

    for (int j = 1; j <= n; ++j) {
        int l = 1, r = j, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (pre[mid - 1] <= pre[j] - gmax * (j - mid + 1)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ans != -1) {
            smax = max(smax, (pre[j] - pre[ans - 1]) / (j - ans + 1));
        }
    }
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++mp[a[i]];
        pre[i] = pre[i - 1] + a[i];
    }
    an = *max_element (a + 1, a + n + 1);
    cout << an;
    f();
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
