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
#define task "RACE"

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
int min_dis = LLONG_MAX;

void sub1() {
    min_dis = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            min_dis = min(min_dis, abs(a[j] - a[i]));
        }
    }
    cout << min_dis;
}

void sub2() {
    min_dis = LLONG_MAX;
    sort (a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i) {
        min_dis = min(min_dis, abs(a[i] - a[i - 1]));
    }
    cout << min_dis;
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n <= 10e3) {
        sub1();
    }
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
