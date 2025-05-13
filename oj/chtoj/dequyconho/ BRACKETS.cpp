#include <bits/stdc++.h>
#define int long long
#define MOD 123456789
#define task "BRACKETS"

using namespace std;

const int N = 1005;
int n, k;
int f[N][N][2];

int dq(int i, int cnt, int maxc) {
    if (cnt < 0) return 0; 
    if (f[i][cnt][maxc] != -1) {
        return f[i][cnt][maxc];
    }
    if (i == n) {
        return f[i][cnt][maxc] = (maxc && cnt == 0);
    }
    f[i][cnt][maxc] = 0;
    if (cnt < k) {
        f[i][cnt][maxc] = (f[i][cnt][maxc] + dq(i + 1, cnt + 1, maxc || (cnt + 1 == k))) % MOD;
    }
    if (cnt > 0) {
        f[i][cnt][maxc] = (f[i][cnt][maxc] + dq(i + 1, cnt - 1, maxc)) % MOD;
    }
    return f[i][cnt][maxc];
}

void logic() {
    cin >> n >> k;
    memset(f, -1, sizeof(f));
    if (n % 2 != 0 || k == 0 || k > n / 2) {
        cout << 0 << '\n';
        return;
    }
    cout << dq(0, 0, 0) << '\n';
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