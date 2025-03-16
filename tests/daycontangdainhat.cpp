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
int a[N];
vector<int> v;
int ans;

void ql(int i) {
    if (i > n) {
        if (!v.empty()) {
            bool check = true;
            for (int i = 0; i < v.size() - 1; ++i) {
                if (v[i] > v[i + 1]) {
                    check = false;
                }
            }
            if (check == true) {
                ans = max(ans, (int)v.size());
            }
        }
    }
    else {
        for (int j = 0; j <= 1; ++j) {
            if (j == 0) {
                ql(i + 1);
            }
            else {
                v.push_back(a[i]);
                ql(i + 1);
                v.pop_back();
            }
        }
    }
}


void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
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
