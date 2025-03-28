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
#define task "NQUEENS"

const int N = 100;
int n;
bool c[N], cp[N], ct[N];
int pos[N]; 
bool found = false;

void ql(int i) {
    if (i > n) {
        found = true;
        return;
    }
    else {
        for (int j = 1; j <= n; ++j) {
            if (!c[j] && !cp[i - j + n] && !ct[i + j]) {
                c[j] = true;
                cp[i - j + n] = true;
                ct[i + j] = true;
                pos[i] = j; 
                ql(i + 1);
                if (found) {
                    return;
                }
                c[j] = false;
                cp[i - j + n] = false;
                ct[i + j] = false;            
            }
        }
    }
}

void logic() {
    cin >> n;
    ql(1);
    if (found) {
        cout << "YES" << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << pos[i] << '\n';
        }
    }
    else {
        cout << "NO";
        return;
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

