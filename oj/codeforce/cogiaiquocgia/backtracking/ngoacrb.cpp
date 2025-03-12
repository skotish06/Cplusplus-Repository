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
int cnt;

void ql(int i, int op, int cl) {
    if (op > n / 2 or cl > op) {
        return;
    } 
    if (i > n) {
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                ++cnt;
            }
            else cnt = 0;
            if (cnt > k) return;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                cout << "(";
            }
            else {
                cout << ")";
            }
        }
        cout << '\n';
    }
    else{ 
        for (int j = 0; j <= 1; ++j) {
            a[i] = j;
            if (j == 0) {    
                ql(i + 1, op + 1, cl);   
            }
            else {
                ql(i + 1, op, cl + 1);
            }
        }
    }
}

void logic() {
    cin >> n >> k;
    ql(1, 0, 0);
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
