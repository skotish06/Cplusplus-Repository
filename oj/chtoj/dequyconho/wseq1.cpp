// #include <bits/stdc++.h>
#include <iostream>
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
#define task "WSEQ1"

using namespace std;
const int N = 1e6 + 9;
int n, m, k;
int a[N];
int res = INF;

void ql(int i, int del, int st, int pos) {
    if (i > n) {
        res = min(res, st);
    }
    else {
        if (del < m) {
            ql(i + 1, del + 1, st, pos);
        }
        int c = ((pos % k) == 0) ? 0 : a[i];
        ql(i + 1, del, st + c, pos + 1);
    }
}

void logic() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ql(1, 0, 0 , 1);
    cout << res;
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



