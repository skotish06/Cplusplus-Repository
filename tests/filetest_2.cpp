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
#define task "PERMUTATION"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int cnt;
int f[N], a[N];
bool c[N] = {false};
int pos;

void fac() {
    f[0] = 1;
    for (int i = 1; i <= 25; i++) {
        f[i] = f[i - 1] * i;
    }
}

void logic() {
    while (cin.peek() != '\n' and cin >> n) {
        a[++cnt] = n;
    }
    cin >> k;
    pos = 1;
    for (int i = 1; i <= cnt; ++i){
        for (int j = i; j < a[i]; ++j)
            pos += f[cnt - i];
    }
    cout << pos << '\n';
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            if (!c[j]) {
                if (k <= f[n - i]) {
                    cout << j << ' ';
                    c[j] = true;
                } 
                else {
                    k -= f[n - i];
                }
            }
        }
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

    fac();
    logic();

    return 0;
}
