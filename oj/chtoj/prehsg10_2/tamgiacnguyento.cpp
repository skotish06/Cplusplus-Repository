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
#define task "TRIANGLE"

using namespace std;
const int N = 1e7 + 9;

bool f[N];
int a[N];
int hang[N], cot[N];
bool snt[N];

void build() {
    memset(f, true, sizeof(f));
    f[0] = f[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (f[i]) {
            for (int j = i * i; j < N; j += i) {
                f[j] = false;
            }
        }
    }
    int k = 0;
    FOR(i, 2, N) {
        if (f[i]) {
            a[++k] = i;
            snt[i] = true;
        }
    }
    int h = 1, c = 1, cnt = 0;
    while (cnt < k) {
        for (int i = 1; i <= h and cnt < k; ++i) {
            hang[a[cnt + 1]] = h;
            cot[a[cnt + 1]] = i;
            cnt++;
        }
        h++;
    }
}

void logic() {
    build();
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        if (!snt[x]) {
            cout << -1 << '\n';
        } else {
            cout << hang[x] << " " << cot[x] << "\n";
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