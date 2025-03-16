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

string dtb(int n) {
  string bin = ""; 
  while (n > 0) {
      int bit = n & 1;
      bin.push_back('0' + bit);
      n = n >> 1;
  }  
  reverse(bin.begin(), bin.end());
  return bin;
}

void logic() {
    while (cin >> n) {
        cout << dtb(n) << '\n';
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
