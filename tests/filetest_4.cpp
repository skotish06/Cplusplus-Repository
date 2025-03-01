#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
ll a[N], n, k, f[N], ans = 0, s[N];
void sol()
{
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll id = lower_bound(s + 1, s + n + 1, s[i] - k) - s;
        f[i] = 2 * f[id - 1] + i;
    }
    for (int i = 1; i <= n; i++)
        ans += f[i];
    cout << ans;
}
main()
{
    skibidi;
    // file("ql")
    cin >> n >> k;
    sol();
}