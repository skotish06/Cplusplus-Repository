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
#define task "PERMUTATION"

using namespace std;
const int N = 1e6 + 9;
int n, k;
int a[N], p[N], cmp[N];
int cnt, d, v;
bool c[N];
bool found = false;
vector<int> ans;

void ql(int i) {
    if (i > cnt) {
        ++d;
        if (!found) { 
            bool check = true;
            for (int j = 1; j <= cnt; ++j) {
                if (a[j] != p[j]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                v = d;
                found = true;
            }
        }

        if (d == k) { 
            for (int j = 1; j <= cnt; ++j) ans.push_back(a[j]);
        }
    }
    else {
        for (int j = 1; j <= n; ++j) {
            if (!c[j]) {
                c[j] = true;
                a[i] = j;
                ql(i + 1);
                c[j] = false;
            }
        }
    }
}

void logic() {
    while (cin.peek() != '\n' && cin >> n) {
        p[++cnt] = n;
    }
    cin >> k;
    ql(1);
    cout << v << '\n';
    for (auto x : ans) {
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
