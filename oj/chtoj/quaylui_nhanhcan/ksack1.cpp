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
#pragma GCC optimize("O3")
#pragma GCC optimize("O1")
#pragma GCC optimize("O1")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

using namespace std;
const int N = 1e6 + 9;
int n, m, res;
int w[N], v[N];
vector<int> tmp, ans;
int pre[N];
int sum, val;

void ql(int i) {
    if (sum > m or w[i] > m) return;
    if (val + pre[n] - pre[i - 1] < res) return;
    if (i > n) {
        if (val > res) {
            res = val;
            ans = tmp;
        }
    }
    else {
        if (val + v[i] + pre[n] - pre[i - 1] >= res and sum + w[i] <= m) {
            tmp.push_back(1);
            sum += w[i];
            val += v[i];
            ql(i + 1);
            sum -= w[i];
            val -= v[i];
            tmp.pop_back();
        }
        if (val + pre[n] - pre[i - 1] >= res) {
            tmp.push_back(0);
            ql(i + 1);
            tmp.pop_back();
        }
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    ql(1);
    cout << res << '\n';
    for (int i = 0; i < (int)ans.size(); i++) {
        if (ans[i] == 1) {
            cout << i + 1 << " ";
        }
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
