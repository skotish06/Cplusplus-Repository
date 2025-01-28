#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005; // Giới hạn theo đề bài
int a[N + 1]; // Mảng bắt đầu từ chỉ số 1

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    for (int i = 1; i <= n; i++) {
        cin >> a[i]; // Nhập mảng bắt đầu từ chỉ số 1
    }

    sort(a + 1, a + n + 1); // Sắp xếp mảng từ chỉ số 1 đến n

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        // Tìm j lớn nhất sao cho a[i] + a[j] <= r
        int max_j = upper_bound(a + i + 1, a + n + 1, r - a[i]) - a - 1;
        
        // Tìm j nhỏ nhất sao cho a[i] + a[j] >= l
        int min_j = lower_bound(a + i + 1, a + n + 1, l - a[i]) - a;

        if (min_j <= max_j) cnt += (max_j - min_j + 1);
    }

    cout << cnt << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}