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
int n, k;
int a[N], b[N];
vector<int> v;
int sum, ans = -1;

void ql(int i) {
    if (i > n) {
        if (v.size() == k) {
            ans = max(ans, sum);
        }
    }
    else {
        for (int j = 0; j <= 1; ++j) {
            if (j == 0) {
                ql(i + 1);
            }
            else { 
                if (v.empty() || a[v.back()] != a[i]) {
                    v.push_back(i);
                    sum += b[i];
                    ql(i + 1);
                    sum -= b[i];
                    v.pop_back();
                }
            }
        }
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
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
