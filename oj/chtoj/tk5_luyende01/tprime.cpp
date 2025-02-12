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
#define task "TPRIME"

using namespace std;
const int N = 5e6 + 9;
int n, a[N], k;
bool f[N];

// void sieve() {
//     memset(f, true, sizeof(f));
//     f[0] = f[1] = false;
//     for (int i = 2; i * i < N; ++i) {
//         if (f[i]) {
//             for (int j = i * i; j < N; j += i) {
//                 f[j] = false;
//             }
//         }
//     }
// }

bool isPrime(int x) {
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void sub12() {
    int cnt = 0;
    REP(x, k) {
        FOR(y, x + 1, k) {
            int z = a[x] * a[x] + a[y] * a[y];
            if (z <= n and isPrime(z)) {
                cnt++;
            }
        }
    }
    cout << cnt;
}

void logic() {
    cin >> n;
    REP(i, n) {
        if (isPrime(i)) {
            a[++k] = i;
        }
    }
    sub12();
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
