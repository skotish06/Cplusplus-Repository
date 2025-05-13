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
int a[N], x;
bool f[N];
int n, k, m;
int ans;
int j;
int prime[N];
int pre[N];

void sieve() {
    memset(f, true, sizeof(f));
    f[0] = f[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (f[i]) {
            for (int j = i * i; j < N; j += i) {
                f[j] = false;
            }
        }
    }
}

void logic() {
    sieve();
    FOR(i, 2, N) { 
        if (f[i]) {
            a[++k] = i;
        }
    }
    cin >> n >> m;
    while (n--) {
        cin >> x;
        int lower_primeNum = lower_bound(a + 1, a + k + 1, x) - a - 1;
        int upper_primeNum = lower_bound(a + 1, a + k + 1, x) - a;
        prime[++j] = ((abs(x - a[lower_primeNum]) >= abs(x - a[upper_primeNum])) ? abs(x - a[upper_primeNum]) : abs(x - a[lower_primeNum]));
    }
    REP(i ,j) {
        pre[i] = pre[i - 1] + prime[i];
    }
    ans = INF;
    FOR(i, m, j) {
        ans = min(ans, pre[i] - pre[i - m]);
    }
    cout << ans;
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