#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define task ""

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
int n;
int a[N], pre[N];
int ans = 0;

void logic() {
    cin >> n;
    pre[0] = INF;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = min(pre[i - 1], a[i]);
    }
    for (int i = 2; i <= n; ++i) {
        ans += a[i] - pre[i - 1];
    }
    cout << ans;
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

/*
pre[i] = min(pre[i - 1], a[i])
ans = a[i] - min(a[1], ..., a[i - 1]);

*/