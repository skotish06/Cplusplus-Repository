#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "COMBIN"

using namespace std;
const int N = 25;
int n, k, m;
vector<int> a;
int cnt;

void ql(int i) {
    if (a.size() >= k) {
        if (cnt == m) {
            for (int x : a) cout << x << ' ';
            cout << '\n';
            exit(0);
        }
        cnt++;
    }
    else {
        for (int j = i; j <= n; ++j) {
            a.push_back(j);
            ql(j + 1);
            a.pop_back();
        }
    }
}

void logic() {
    cin >> n >> k >> m;
    ql(1);
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