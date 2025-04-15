// #include <bits/stdc++.h>
#include <iostream>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task ""

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N], b[N], c[N];
int dp[N][3];
int maxx = -INF;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + a[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + b[i];
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
    } 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            maxx = max(maxx, dp[i][j]);
        }
    }  
    cout << maxx;
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
dp[i][j]: độ vui lớn nhất mà Thanh có thể nhận được sau i ngày nghỉ
và nếu
j = 1 đi bơi
j = 2 đi bắt bọ
j = 3 đi xaay lâu đài cát

xét i:
    - ngày i đi bơi
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + a[i]
    - ngày i đi bắt bọ
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + b[i]
    - ngày i đi xây lâu đài cát
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + c[i]
*/