#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    sort(t + 1, t + n + 1);

    int res = 0, on = 0, off = 0, cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (cnt < k) {
            if (i == 1 || t[i] > off) {
                on = t[i];
                off = t[i] + 1;
                cnt++;
            }
        } else if (t[i] <= off) {
            off = max(off, t[i] + 1);
        } else {
            if (cnt >= k) {
                off = t[i] + 1;
            } else {
                on = t[i];
                off = t[i] + 1;
                cnt++;
            }
        }
        res = off - on;
    }

    cout << res << "\n";
    return 0;
}