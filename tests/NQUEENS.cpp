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

using namespace std;
const int N = 100;
int n;
bool c[N], cp[N], ct[N];
int pos[N]; 
bool found = false;
vector<pii> qns;

void ql(int i) {
    if (i > n) {
        found = true;
        return;
    }
    else {
        for (int j = 1; j <= n; ++j) {
            if (!c[j] && !cp[i - j + n] && !ct[i + j]) {
                c[j] = cp[i - j + n] = ct[i + j] = true;
                pos[i] = j; 
                ql(i + 1);
                if (found) {
                    return;
                }
                c[j] = cp[i - j + n] = ct[i + j] = false;            
            }
        }
    }
}

void sub12() {
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

void sub3() {
    if (n == 1) {
        cout << "YES\n1 1\n";
        return;
    }
    if (n == 2 || n == 3) {
        cout << "NO\n";
        return;
    }
    int mid = n / 2;
        for (int i = 1; i <= mid; ++i) {
        qns.pb({i, 2 * i});
    }
    for (int i = 1; i <= mid; ++i) {
        qns.pb({mid + i, 2 * i - 1});
    }
    if (n & 1) {
        qns.pb({n, n});
    }
    cout << "YES\n";
    for (auto [x, y] : qns) {
        cout << x << ' ' << y << '\n';
    }
}


void logic() {
    cin >> n;
    // if (n <= 20) sub12();
    // else sub3();
    sub3();
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
