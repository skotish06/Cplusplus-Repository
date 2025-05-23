#include <bits/stdc++.h>
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
#define task "ABC"

using namespace std;
const int N = 1e6 + 9;

int n, cnt;
string res;

void logic() {
    cin >> n;
    string s = "ABACABCBAB";
    for (int i = 0; i < n; i++) {
        res += s[i % 4];
    }
    for(int i = 0; i < res.size(); ++i) {
        if (res[i] == 'C') {
            ++cnt;
        }
    }
    cout << res << '\n' << cnt;
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
