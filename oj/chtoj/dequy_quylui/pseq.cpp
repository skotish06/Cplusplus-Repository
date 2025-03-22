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
vector<int> odd, even, tmp;
bool f[N];

void sieve() {
    memset(f, true, sizeof(f));
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (f[i]) {
            for (int j = i * i; j <= N; j += i) {
                f[j] = false;
            }
        }
    }
}

void logic() {
    sieve();
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i & 1) odd.push_back(i);
        else even.push_back(i);
    }
    tmp.resize(2 * n + 1);
    tmp[1] = 1;
    for (int i = 2; i <= 2 * n; ++i) {
        if (i & 1) {
            for (int j = odd.size() - 1; j >= 0; --j) {
                if (f[tmp[i - 1] + odd[j]]) {
                    tmp[i] = odd[j];
                    odd.erase(odd.begin() + j);
                    break;
                }
            }
        }
        else {
            for (int j = even.size() - 1; j >= 0; --j) {
                if (f[tmp[i - 1] + even[j]]) {
                    tmp[i] = even[j];
                    even.erase(even.begin() + j);
                    break;
                }
            }
        }
    }

    for (int i = 1; i < (int)tmp.size(); ++i) {
        cout << tmp[i] << " ";
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



// inspired by nm