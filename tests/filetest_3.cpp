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
#define task "NECK"

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
deque<int> dq;
map<int, int> mp;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++mp[a[i]];
    }
    dq.push_back(a[1]);
    for (int i = 2; i <= n; ++i) {
        if (a[i] > dq.back()) {
            dq.push_back(a[i]);
        }
        else if (a[i] < dq.front()) {
            dq.push_front(a[i]);
        }
        else if (a[i] < dq.back() and a[i] > dq.front()) {
            continue;
        }
        else if (mp[a[i]] > 1) {
            continue;
        }
    }
    cout << dq.size();
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
