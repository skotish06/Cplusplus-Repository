#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task "GCDRECT"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int m, n;
int st[N];
int res;
int a[N][N], b[N][N];
int h[N], l[N], r[N];

void logic() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int x = 2; x <= 2e2 + 9; ++x) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                b[i][j] = (a[i][j] % x == 0);
            }
        }
        memset(h, 0, sizeof(h));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                h[j] = b[i][j] ? h[j] + 1 : 0;
            }
            int top = -1;
            for (int j = 0; j < n; ++j) {
                while (top >= 0 && h[st[top]] >= h[j]) --top;
                l[j] = (top == -1 ? -1 : st[top]);
                st[++top] = j;
            }
            top = -1;
            for (int j = n - 1; j >= 0; --j) {
                while (top >= 0 && h[st[top]] >= h[j]) --top;
                r[j] = (top == -1 ? n : st[top]);
                st[++top] = j;
            }
            for (int j = 0; j < n; ++j) {
                res = max(res, h[j] * (r[j] - l[j] - 1));
            }
        }
    }

    cout << res << '\n';
    // execute;
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
--/shouko\--
DRAFT:


------------
*/
