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
int n, k;
int a[N], p[N];
int pos;
int c;
int j;
vector<int> vt;

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        p[i] = i + (n - k);
    }
    for (int i = k; i >= 1; --i) {
        if (a[i] != p[i]) {
            pos = i;
            break;
        }
    }
    for (int i = 1; i < pos; ++i) {
        vt.push_back(a[i]);
    }
    for (int i = pos; i <= k; ++i) {
        ++j;
        vt.push_back(a[pos] + j);
    }
    if (vt.size() != k) {
        cout << "NOTAVAILABLE";
        return;
    }
    for (auto x : vt) {
        cout << x << ' ';
    }
}
/*
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5


*/
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
