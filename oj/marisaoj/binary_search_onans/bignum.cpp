#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;
int n, k;
int a[N];

bool check(int x) {
    int cnt = 1, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i] > x) { 
            cnt++;
            sum = a[i];  
            if (cnt > k) return false;
        } else {
            sum += a[i];
        }
    }
    return true;
}

void logic() {
    cin >> n >> k;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l = max(l, a[i]);  // Giá trị lớn nhất trong mảng
        r += a[i];         // Tổng của mảng
    }

    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid; 
        else l = mid + 1;
    }
    cout << l << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    logic();
    return 0;
}