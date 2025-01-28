#include <bits/stdc++.h>

#define NAME "GBOMB"
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

pair<ll,ll> ans[N];
ll d = 0;

void solve(){

    ll n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++){

        ll l = 0, r = 0;

        for (int j = 1; j <= m; j++){

            char x; cin >> x;
            if (x == 'x') {
                if (!l) l = j;
                r = j;
            }
            if (x == '#'){
                if (l != 0 and r != 0){
                    ans[++d].first = l;
                    ans[d].second = r;
                }

                l = 0, r = 0;
            }
        }
        if (l != 0 and r != 0){
            ans[++d].first = l;
            ans[d].second = r;
        }

    }
    if (d > k) cout << -1;
    else{
        ll mx = 0;
        for (int i = 1; i <= d; i++){
            ll p = (ans[i].first + ans[i].second) / 2;
            mx = max({mx, p - ans[i].first, ans[i].second - p});
        }
        cout << mx;
    }
    
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
