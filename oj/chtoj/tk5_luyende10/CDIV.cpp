#include <bits/stdc++.h>

#define NAME "CDIV"
#define i32 int
#define i64 int64_t
#define u32 unsigned int
#define u64 unsigned long long
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vec vector
#define fi first
#define se second
#define sz(a) (u32)(a.size())
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()
#define debug(x) cout << #x << ": " << (x) << "\n";

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 6 * 1e5 + 5;
const int INF = 1e9;
const ld EPS = 1e-9;

ll L, H, a, b;

void solve(){

    cin >> L >> H >> a >> b;

    ll x = (a * b) / (__gcd(a, b));

    cout << H / x - (L - 1) / x;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(NAME ".inp", "r")){
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }

    ll t; t = 1;

    while(t--){
        solve();
    }

    return 0;
}
