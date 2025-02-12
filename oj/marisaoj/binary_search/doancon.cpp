#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 9;
int n, S, res = -1;
int a[N], pre[N];

void logic() {
    cin >> n >> S;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int j = 1; j <= n; ++j) {
        int l = 1, r = j, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (pre[j] - pre[mid - 1] <= S) {  // Sửa điều kiện
                ans = mid;
                r = mid - 1;  // Tiếp tục tìm đoạn nhỏ hơn
            } else {
                l = mid + 1;
            }
        }
        if (ans != -1) {
            res = max(res, j - ans + 1);
        }
    }

    cout << res << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    logic();
    return 0;
}