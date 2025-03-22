#include <bits/stdc++.h>

#define NAME "PERMUTATION"
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
const int N = 1e5 + 5;
const int INF = 1e9;
const ld EPS = 1e-9;

vector < ll > a(N);
vector < bool > used (N, false);
ll p[N];
ll n = 0, k;

void solve(){

    ll x;
    while (cin >> x){
        a[++n] = x;
    }

    k = a[n--];

    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] * i;

    
    ll ans1 = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < a[i]; j++)
            if (!used[j])
                ans1 += p[n - i];
        used[a[i]] = true;
    }

    cout << ans1 << '\n';

    for (int i = 1; i <= n; i++) used[i] = false;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            if (!used[j]){
                if (k > p[n - i])
                    k -= p[n - i];
                else{
                    cout << j << ' ';
                    used[j] = true;
                    break;
                }
            }
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
