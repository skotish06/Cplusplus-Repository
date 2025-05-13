#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task ""

using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n;
int a[N];
int dpl[N], dpr[N];

void tracel(int i) {
    int pos = 0;
    for (int j = 1; j < i; ++j) {
        if (a[i] > a[j] && dpl[i] == dpl[j] + 1) {
            pos = j;
            break;
        }
    }
    if (pos != 0) tracel(pos);
    cout << i << ' ';
}

void tracer(int i) {
    int pos = 0;
    for (int j = i + 1; j <= n; ++j) {
        if (a[i] > a[j] && dpr[i] == dpr[j] + 1) {
            pos = j;
            break;
        }
    }
    if (pos != 0) {
        cout << pos << ' ';
        tracer(pos);
    }
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        dpl[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i] > a[j]) {
                dpl[i] = max(dpl[i], dpl[j] + 1);
            }
        }
    }

    for (int i = n; i >= 1; --i) {
        dpr[i] = 1;
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] > a[j]) {
                dpr[i] = max(dpr[i], dpr[j] + 1);
            }
        }
    }

    int ans = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        int temp = 2 * min(dpl[i], dpr[i]) - 1;
        if (temp > ans) {
            ans = temp;
            pos = i;
        }
    }
    cout << ans << '\n';
    tracel(pos); 
    tracer(pos);
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