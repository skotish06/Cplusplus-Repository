#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);\
                    cin.tie(0);\
                    cout.tie(0)
#define task ""
#define fopenn(tenfile) if(fopen(tenfile".inp","r")){\
                            freopen (tenfile".inp","r",stdin);\
                            freopen (tenfile".out","w",stdout);\
                        }
/*#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define compile (1.0 clock() / CLOCKS_PER_SEC)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse4,avx2,fma")*/
#define ull unsigned long long
#define ld long double
#define ll long long
#define str string
#define endl "\n"
#define ch char
using namespace std;
const ll N=1e5+19;
const ll MOD=1e9+7;
const ll MAXN=1e7+1;
ll res=0,dp[5019][5019],f[5019][5019];
str s;
ll n,d=0;
void solve()
{
    cin>>s;
    n=s.size();
    s=" "+s;
    for(ll i=1;i<=n;i++){
        dp[i][i]=1;
    }
    for(ll r=1;r<=n;r++){
        for(ll l=r-1;l>=1;l--){
            if(s[l]==s[r]&&dp[l+1][r-1]) dp[l][r]=1;
            if(s[l]==s[r]&&l+1==r) dp[l][r]=1;
            if(dp[l][r]) res++;
        }
    }
    for(ll r=1;r<=n;r++){
        for(ll l=r-1;l>=1;l--){
            if(dp[l][r]){
                f[l][r]=1;
            }else{
                for(ll mid=l+1;mid<r;mid++){
                    if(f[l][mid]&&f[mid+1][r]){
                        f[l][r]=1;
                    }
                }
            }
            if(f[l][r]) d++;
        }
    }
    cout<<d;
}
signed main(){
    ios;
    fopenn("PALIND3");
    solve();
}