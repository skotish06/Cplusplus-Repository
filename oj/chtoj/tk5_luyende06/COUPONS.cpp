#include<bits/stdc++.h>
#define task "coupons"
#define ii pair<int, int>
#define ll long long
#define ld long double
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F if(fopen(task".inp","r")){ freopen(task".inp","r",stdin); freopen(task".out","w",stdout); }
using namespace std;

const int Q = 1e6 + 21;
ll n;
ll m;
ll k;

struct cs
{
    ll a;
    ll b;
};

bool cmp(cs x, cs y)
{
    if(x.b < y.b)
        return true;
    if(x.b == y.b && x.a < y.a)
        return true;
    return false;
}

cs t[Q];

signed main()
{
    faster;
    F;

    cin >> n;
    cin >> k;
    cin >> m;

    for(int i = 1; i <= n; i++)
    {
        cin >> t[i].a;
        cin >> t[i].b;
    }

    sort(t + 1, t + n + 1, cmp);

    ll dem = 0;
    ll dc = 0;

    for(int i = 1; i <= n; i++)
    {
        if(dc < k)
        {
            dc++;
            m -= t[i].b;
        }
        else
        {
            m -= t[i].a;
        }

        if(m >= 0)
            dem++;
    }

    cout << dem;
    return 0;
}