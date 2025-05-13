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
int n, k, m;
int a[N];
int sum;
pair<vector<int, int>, int> z;

void ql(int i) {
    if (i > n) {
        if (sum == k) {
            cout << a[1];
            for (int i = 2; i <= n; ++i) {
                if (a[i] < 0) {
                    cout << " - ";
                }
                else {
                    cout << " + ";
                }
                cout << abs(a[i]);
            }
            cout << '\n';
        }
    }
    else {
        if (i == 1) {
            for (int j = 1; j <= 5; ++j) {
                a[i] = j;
                sum += a[i];
                ql(i + 1);
                sum -= a[i];
            }
        }
        else {
            for (int j = 1; j <= 5; ++j) {
                if (j != 0) {
                    a[i] = j;
                    sum += a[i];
                    ql(i + 1);
                    sum -= a[i];
                }
            }
            for (int j = 0; j >= -5; --j) {
                if (j != 0) {
                    a[i] = j;
                    sum += a[i];
                    ql(i + 1);
                    sum -= a[i];
                }
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
