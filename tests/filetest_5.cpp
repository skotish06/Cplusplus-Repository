#include<bits/stdc++.h>
using namespace std;
#define task "SPOR"
const int N = 1e6 + 9;
const int M = 1e9 + 7;
typedef long long ll;

ll n;
ll s[N], f[N];

map<ll,ll> m;
pair<ll,ll> a[N];

ll mi = LLONG_MAX, mx = LLONG_MIN;

void sub12(){

    sort(a + 1, a + n + 1);
    ll ans = mx - mi + 1, L = a[1].first, R = a[1].second;

    for (int i = 1; i <= n; i++){

        if (a[i].first <= R){
            R = max(R, a[i].second);
        }
        else{
            ans -= (R - L + 1);

            L = a[i].first;
            R = a[i].second;

            // if (i == n) ans -= (R - L + 1);
        }

    }

    // if (L != a[n].first and R != a[n].second)
        ans -= (R - L + 1);

    cout << ans;

}

void sub3(){

    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));

    ll ans = 0;

    for (int i = 1; i <= n; i++){
        f[a[i].first]++;
        f[a[i].second + 1]--;
    }

    for (int i = mi; i <= mx; i++){
        s[i] = s[i - 1] + f[i];

        ans += (s[i] == 0);
    }

    cout << ans;

}
int main(){
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(fopen(task ".inp", "r")){
            freopen(task ".inp", "r", stdin);
            freopen(task ".out", "w", stdout);
        }
    }


    cin >> n;

    for (int i = 1; i <= n; i++){

        cin >> a[i].first >> a[i].second;

        mi = min(mi, a[i].first);
        mx = max(mx, a[i].second);

    }

    
    if (n <= 100000) sub12();
    else sub3();
}
