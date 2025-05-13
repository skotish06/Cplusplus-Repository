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
#define task "SUBSTRG"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, k;
string s;
map<char, int> mp;

void logic() {
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    int l = 1;
    int ans = 0, pos = 1;
    for (int r = 1; r <= n; ++r) {
        ++mp[s[r]];
        while (mp[s[r]] > k) {
            --mp[s[l++]];
        }
        if (r - l + 1 > ans) {
            ans = r - l + 1;
            pos = l;
        }
    }   
    cout << ans << ' ' << pos << '\n';
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
