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
int a[N];
int c[N];
int p[N];
int cnt;
set<int> s;

void ql(int i) {
    if (i > n) {
        s.clear();
        for (int i = 1; i <= k; ++i) {
            s.insert(c[i]);
        }
        if ((int)s.size() == 1 and cnt != 1) {
            for (int i = 1; i <= n; ++i) {
                cout << p[i] << ' ';
            }
            ++cnt;
        }
    }
    else {
        for (int j = 1; j <= k; ++j) {
            c[j] += a[i];
            p[i] = j;
            ql(i + 1);
            c[j] -= a[i];
        }
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ql(1);
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
