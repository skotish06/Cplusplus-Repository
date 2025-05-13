#include <bits/stdc++.h>
#define int long long
#define aint(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task ""


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, k;
int a[N];
pair<int, int> preff[N];

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        preff[i].fi = preff[i - 1].fi + a[i];
        preff[i].se = preff[i - 1].se + k;
    }
    for (int i = 1; i <= n; ++i) {
        int pos = upper_bound(a + i + 1, a + 1 + n, 1.0*(m + 2 * a[i]) / 2) - a;
        pos--;
        int cnt = 0;
        cnt = pref[pos].fi - pref[i].fi - (pos - i) * a[i];
        cnt += (pref[n].se - pref[pos].se) - (pref[n].fi - pref[pos].fi) + (n - pos) * a[i];
        pos = lower_bound(a + 1, a + i, 1.0*(2 * a[i] - m) / 2) - a;
        cnt += a[i] * (i - pos) - (pref[i - 1].fi - pref[pos - 1].fi);
        cnt += pref[pos - 1]. + (pos - 1) * (m - a[i]);
        //cout<<cnt<<'\n';
        ans = min(ans, cnt);

    }
    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NUint);
    cout.tie(NUint);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:

xét a[i]
x <- a[i]
nếu x < a[i]
    x - a[i] <= k - x + a[i]
    2 * x <= k + 2 * a[i]
    x <= (k + 2 * a[i]) / 2


nếu x > a[i]
    a[i] - x <= k + x - a[i]
    2 * a[i] - k <= 2 * x
    x >= (2 * a[i] - k) / 2 

------------
*/
