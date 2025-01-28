#include <bits/stdc++.h>
#define int long long
#define task "INTP"
using namespace std;
const int N = 1e6 + 9;
const int M = 510;
int a[N];
int k, x;
bool f[M];
int n;

void sieve() {
    memset(f, true, sizeof(f));
    f[0] = f[1] = false;
    for (int i = 2; i * i <= M; i++) {
        if (f[i]) {
            for (int j = i * i; j < M; j += i) {
                f[j] = false;
            }
        }
    }
}

int ptso(int x) {
    int ans = 0;
    while (x != 0) {
        int d = x % 10;
        ans += d * d;
        x /= 10;
    }
    return ans;
}

void solve() {
    sieve();
    for (int i = 1; i <= N; i++) {
        if (f[ptso(i)]) {
            a[++k] = i;
        }
    }
    cin >> n;
    while (n--) {
        cin >> x;
        int ans = upper_bound(a + 1, a + k + 1, x) - a;
        cout << a[ans] << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();

    return 0;
}