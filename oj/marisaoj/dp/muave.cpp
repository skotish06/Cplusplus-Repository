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
#define task ""


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n;
int t[N], r[N], dp[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> r[i];
    }
    dp[1] = t[1];
    dp[2] = min(t[1] + t[2], r[1]);
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
    }
    cout << dp[n];
    //execute;
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
