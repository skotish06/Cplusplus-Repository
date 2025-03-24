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
#define task "KSACK1"

using namespace std;

const int N = 1e6 + 9;
int n, v;
pii a[N];
int we = 0, va = 0, ans = 0;
vector<int> w, w_ans;

void ql(int i) {
    if (we > v) return; 
    if (i > n) { 
        if (va > ans) { 
            ans = va;
            w_ans = w; 
        }
    }
    else {
        for (int j = 0; j <= 1; ++j) {
            if (j == 1) { 
                ql(i + 1);
            } else { 
                w.push_back(i);
                we += a[i].fi;
                va += a[i].se;
                ql(i + 1);
                w.pop_back();
                we -= a[i].fi;
                va -= a[i].se;
            }
        }
    }
}

void logic() {
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    ql(1);
    cout << ans << '\n';
    for (auto x : w_ans) {
        cout << x << ' ';
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
