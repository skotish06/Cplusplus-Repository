#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define task ""

using namespace std;
const int N = 1e2 + 9;
const int M = 1e6 + 5;
int n, w;
int a[N];
int dp[M];

void logic() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= w; j++) {
        for (int i = 1; i <= n; i++) {
            if (j - a[i] >= 0) {
                dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
            }
        }
    }
    cout << dp[w];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();

    return 0;
}

/*
dp[j]: số cách để tạo tổng j (không phân biệt thứ tự)
Duyệt từng phần tử a[i], cập nhật từ nhỏ đến lớn để tránh đếm trùng
*/