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

ll n, m, k;

bool check(ll x, vector<ll> a[]){

    ll res = 0;

    for (int i = 1; i <= n; i++){
        ll p = 0, d = 0;

        for (int j = 1; j <= m; j++){
            if (a[i][j] == 1){
                if (j <= p) continue;
                else{
                    d++;
                    p = j + 2 * x;
                }
            }
            if (a[i][j] == 2){
                p = 0;
            }
        }
        
        res += d;
    }

    return (res <= k);
}


void solve(){

    cin >> n >> m >> k;

    vector<ll> a[n + 1];


    for (int i = 1; i <= n; i++){
        a[i].resize(m);
        ll l = 0, r = 0;

        for (int j = 1; j <= m; j++){

            char x; cin >> x;
            if (x == 'x') a[i][j] = 1;
            if (x == '#') a[i][j] = 2;
        }

    }
    ll l = 0, r = m;
    ll ans = -1;

    while(l <= r){
        ll mid = (l + r) / 2;
        if (check(mid, a)){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }

    cout << ans;
    
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
