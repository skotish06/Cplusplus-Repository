#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define task "FRACTION"

using namespace std;
const int N = 1e3 + 9;

int n, w;
pair<int, int> a[N];
double f[N], g[N];

int lis(const vector<double>& v) {
    vector<double> lis;
    for (size_t i = 0; i < v.size(); ++i) {
        double x = v[i];
        vector<double>::iterator it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.push_back(x);
        else *it = x;
    }
    return lis.size();
}

void logic() {
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
        f[i] = (double)a[i].fi / a[i].se;
        g[i] = (double)a[i].se / a[i].fi;
    }

    vector<double> v(n);
    for (int i = 1; i <= n; ++i) v[i - 1] = f[i];
    int ans = lis(v);

    if (w == 1) {
        for (int i = 1; i <= n; ++i) {
            vector<double> temp(n);
            for (int j = 1; j <= n; ++j) {
                if (j == i) temp[j - 1] = g[j];
                else temp[j - 1] = f[j];
            }
            ans = max(ans, lis(temp));
        }
    }

    cout << ans << '\n';
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
