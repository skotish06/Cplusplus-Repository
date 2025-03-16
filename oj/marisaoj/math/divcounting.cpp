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
int l, r;
int p[N];
int pre[N];

void div_count() {
    fill (p + 1, p + N + 1, 2);
    for (int i = 2; i * i <= N; ++i) {
        p[i * i]--;
        for (int j = i * i; j <= N; j += i) {
            p[j] += 2;
        }
    }
}

void logic() {
    div_count();
    for (int i = 1; i <= N; ++i) {
        pre[i] = pre[i - 1] + p[i];
    }
    cin >> l >> r;
    cout << pre[r] - pre[l - 1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int q; cin >> q;
    while (q--) {
        logic();
    }

    return 0;
}
