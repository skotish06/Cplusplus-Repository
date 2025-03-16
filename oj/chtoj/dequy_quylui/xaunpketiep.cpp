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
#define task ""

using namespace std;
const int N = 1e6 + 9;
int pos = LLONG_MIN;
string s, p;

void logic() {
    cin >> s;
    p = s;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            pos = i;
            break;
        }
    }
    if (pos == LLONG_MIN) {
        cout << "NOTAVAILABLE";
        return;
    }
    p[pos] = '1';
    for (int i = pos + 1; i < s.size(); ++i) {
        p[i] = '0';
    }
    cout << p << '\n';
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
