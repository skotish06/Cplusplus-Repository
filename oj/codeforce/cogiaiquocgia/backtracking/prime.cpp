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
int n;
vector<int> dg;
char f[N];
int sum, ans = -1;

bool ngt(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void ql(int i) {
    if (i > dg.size()) {
        if (ngt(sum)) {
            ans = max(ans, sum);
        }
    }
    else {
        for (int j = 0; j <= 1; ++j) {
            if (j == 0) {
                ql(i + 1);
            }
            else {
                sum = sum * 10 + dg[i - 1];
                ql(i + 1);
                sum /= 10;
            }
        }
    }
}


void logic() {
    cin >> n;
    while (n) {
        dg.pb(n % 10);
        n /= 10;
    }
    reverse(dg.begin(), dg.end());
    ql(1);
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
