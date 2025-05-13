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
#define task "HPRIME"

using namespace std;
const int N = 1e6 + 9;
int n, k;
bool f[N];

void sieve() {
    for (int i = 0; i < N; ++i) f[i] = true;
    f[0] = f[1] = false;
    int sq = sqrt(N);
    for (int i = 2; i <= sq; ++i) {
        if (f[i]) {
            for (int j = i * i; j < N; j += i) {
                f[j] = false;
            }
        }
    }
}

int Tsum(int i) {
    int sum = 0;
    while (i) {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

void logic() {
    if (k > 54) return; 
    sieve();
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        if (f[i] and Tsum(i) == k) {
            cout << i << '\n';
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

    logic();

    return 0;
}
