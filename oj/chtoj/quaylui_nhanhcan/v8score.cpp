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
#define task "V8SCORE"

using namespace std;
const int N = 25;
int n, m, k;
int mat[N][N];
int a[N][N];
vector<pair<int, int>> v;
int sum;
bool cmp(pii x, pii y) {
    return x.second < y.second;
}

void ql(int i) {
    if (sum > k) return;
    if (i > m) {
        if (sum == k) {
            cout << "YES\n";
            sort(v.begin(), v.end(), cmp);
            for (auto p : v) {
                cout << a[p.fi][p.se] << ' ';
            }
            exit(0);
        }
    }
    else {
        for (int j = 1; j <= n; ++j) {
            if (mat[j][i-1] == 1) { 
                if (a[j][i] >= a[j][i-1] and a[j - 1][i] >= a[j][i]) {
                    sum += a[j][i];
                    mat[j][i] = 1;
                    v.push_back({j, i});
                    ql(i + 1);
                    v.pop_back();
                    sum -= a[j][i];
                    mat[j][i] = 0;
                }
            } else {
                sum += a[j][i];
                mat[j][i] = 1;
                v.push_back({j, i});
                ql(i + 1);
                v.pop_back();
                sum -= a[j][i];
                mat[j][i] = 0;
            }
        }
    }
}

void logic() {
    cin >> k >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            mat[i][j] = 0;
        }
    }
    ql(1);
    cout << "NO";
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
