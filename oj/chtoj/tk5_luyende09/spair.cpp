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
#define task "SPAIR"

using namespace std;
const int N = 5e6 + 9;
int n, pre[N];
int cnt;
pair <int, int> a[N];
pair <int, int> b[N];
int k;

void sub1() {
    int l = 1, s = 0;
    for (int r = 1; r <= n; ++r) {
       s += r;
       while (s >= n) {
            s -= l;
            ++l;
            if (s == n) {
                ++cnt;
                a[++k].first = l;
                a[k].second = r;
            }
       }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= k; ++i) {
        cout << a[i].first << ' ' << a[i].second << '\n';
    }
}

void sub2() {
        /*
            l + l + 1 + l + 2 + ... r = n
            (l + r) * (r - l + 1) / 2 = n
            (l + r) * (r - l + 1) = 2 * n
            i * j = 2n
            i = l + r
            j = r - l + 1
            => i * j = 2 * n
            l = (i + 2n / i - 1) / 2
            r = (i - 2n / i + 1) / 2
            (i - 2n / i + 1) % 2 == 0 and (2n % i == 0)
        */
    for (int i = 1; i * i <= 2 * n; ++i) {
        if ((2 * n) % i == 0 and (i + (2 * n) / i - 1) % 2 == 0) {
            ++cnt;
            b[cnt].se = (i + (2 * n) / i - 1) / 2;
            b[cnt].fi = 2 * n / i - b[cnt].se;
        }
    }
    cout << cnt << '\n';
    sort(b + 1, b + cnt + 1); 
    for (int i = 1; i <= cnt; ++i) {
        cout << b[i].fi << ' ' << b[i].se << '\n';
    }
}

void logic() {
    cin >> n;
    if (n <= 1e6) sub1();
    else sub2();
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

