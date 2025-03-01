#include <bits/stdc++.h>

#define NAME "DQUERY"
#define i32 int
#define i64 int64_t
#define u32 unsigned int
#define u64 unsigned long long
#define ll long long
#define ld long double
#define ii pair<ll, ll>
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
const int N = 2 * 1e6 + 5;
const int INF = 1e9;
const ld EPS = 1e-9;

ll n, a[N], ans[N], f[N];
ll q;

map < ll, ll > m;

struct pt{
    ll l, r, pos;
};

bool cmp(pt x, pt y){
    return (x.r < y.r || (x.r == y.r && x.l < y.l)) ;
}

pt qu[N];

void update(ll id, ll l, ll r, ll pos, ll val){
    if (l > pos or r < pos) return;
    if (l == r){
        f[id] = val;
        return;
    }
    ll mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    f[id] = f[id * 2] + f[id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (l > v or r < u) return 0;
    if (l >= u and r <= v) return f[id];
    ll mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve(){

    cin >> n >> q;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= q; i++){
        ll x, y; cin >> x >> y;

        qu[i].l = x, qu[i].r = y, qu[i].pos = i;
    }

    sort(qu + 1, qu + q + 1, cmp);

    ll d = 1;

//
    for (int i = 1; i <= n; i++){

        update(1, 1, n, m[a[i]], 0);
        update(1, 1, n, i, 1);
        m[a[i]] = i;

        while (i == qu[d].r){
            ans[qu[d].pos] = get(1, 1, n, qu[d].l, qu[d].r);
            d++;
        }

    }
////
    for (int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
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
