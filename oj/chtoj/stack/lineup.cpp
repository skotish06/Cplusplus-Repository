#include <bits/stdc++.h>
#define int long long
#define task "LINEUP"
using namespace std;
const int N = 1e6 + 9;
int n;
int h[N], lf[N];
stack<int> s;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        while (!s.empty() and h[s.top()] <= h[i]) {
            s.pop();
        }
        if (s.empty()) lf[i] = 0;
        else lf[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << lf[i] - 1 << ' ';
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

    solve();

    return 0;
}
