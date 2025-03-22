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
#define task "COMBIN"

using namespace std;
const int N = 1e6 + 9;
const int M = 100;
int n, k, m;
int c[M][M] = {};
vector<int> s;
int cnt;

void pascalTri() {
    for (int i = 0; i <= 64; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

void logic() {
    pascalTri();
    cin >> n >> k >> m;
    cnt = 1;
    while (k > 0) {
        if (m < c[n - 1][k - 1]) {
            s.push_back(cnt);
            --k;
        } else {
            m -= c[n - 1][k - 1];
        }
        --n;
        ++cnt;
    }
    for (auto x : s) {
        cout << x << ' ';
    }
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
