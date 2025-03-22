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
#define task "ADN"

using namespace std;
const int N = 1e6 + 9;
string s, f;
int ans = LLONG_MAX;

void ql(int i) {
    if (i == (int)s.size()) {
        int cnt = 0;
        for (int i = 0; i < f.size(); ++i) {
            bool A = 0, T = 0, G = 0, X = 0;
            for (int j = i; j < f.size(); ++j) {
                if (f[j] == 'A') {
                    A = true;
                }
                else if (f[j] == 'T') {
                    T = true;
                }
                else if (f[j] == 'G') {
                    G = true;
                }
                else if (f[j] == 'X') {
                    X = true;
                }
                if (A + T + G + X >= 2) {
                    ++cnt;
                }
            }
        }
        ans = min(ans, cnt);
    }
    else {
        if (s[i] != '?') {
            f += s[i];
            ql(i + 1);
            f.pop_back();
        }
        else {
            for (char c : {'A', 'T', 'G', 'X'}) {
                f += c;
                ql(i + 1);
                f.pop_back();
            }
        }
    }
}

void logic() {
    cin >> s;
    ql(0);
    cout << ans;
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
