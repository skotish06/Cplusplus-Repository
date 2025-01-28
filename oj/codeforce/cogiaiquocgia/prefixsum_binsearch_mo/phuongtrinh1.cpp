#include <bits/stdc++.h>
#define int long long
#define task ""
using namespace std;
const int N = 1e6 + 9;
int n, cnt, p;
int a[N], pre[N];

void logic() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int y = 1; y <= n; ++y) {
        int l = 1, r = y;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (pre[mid - 1] == pre[y] - p) {
                ++cnt;
                break;
            }
            else if (pre[mid - 1] > pre[y] - p) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
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

    logic();

    return 0;
}
