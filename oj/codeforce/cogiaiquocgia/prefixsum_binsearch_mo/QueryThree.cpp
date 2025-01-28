#include <bits/stdc++.h>
using namespace std;
const int _size = 100'007;

int n, k, sum[_size], A[_size], l, r, mid, pos;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + A[i];
    for (int i = 1; i <= n; i++) {
        l = 1;
        r = i;
        pos = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (sum[i] - sum[mid - 1] <= k) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << pos << endl;
    }
    return 0;
}