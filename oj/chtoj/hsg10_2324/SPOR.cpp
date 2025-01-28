#include <bits/stdc++.h>
#define int long long
#define task "SPOR"
using namespace std;
const int N = 1e6 + 9;
int n, s1, s2;
int minn = LLONG_MAX, maxx = LLONG_MIN;
int mp[N];
int cnt;


void solve() {
    cin >> n;
    while (n--) {
        cin >> s1 >> s2;
        for (int i = s1; i <= s2; ++i) {
            ++mp[i];
        }
        minn = min(minn, s1);
        maxx = max(maxx, s2);
    }
    for (int i = minn; i <= maxx; ++i) {
        if (mp[i] == 0) {
            ++cnt;
        }
    }
    cout << cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();

    return 0;
}
