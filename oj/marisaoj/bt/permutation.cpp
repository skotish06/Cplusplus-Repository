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
bool c[N];

void ql(int i) {
    if (i > k) {
        for (int i = 1; i <= k; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int j = 1; j <= n; ++j) {
            if (c[j] == false) {
                c[j] = true;
                a[i] = j;
                ql(i + 1);
                c[j] = false;
            }
        }
    }
}

void logic() {
    cin >> n >> k;
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
