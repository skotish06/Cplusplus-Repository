#include <bits/stdc++.h>
#define task "nqueens"
#define int long long
#define ii std::pair<int, int>
#define iii std::pair<ii, int>
#define fi first
#define se second
#define pb push_back
#define ins insert

const int maxn = 1e5;
const int inf = 1e18;

int n;
std::vector<ii> ans;

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    if (std::fopen(task ".inp", "r"))
    {
        std::freopen(task ".inp", "r", stdin);
        std::freopen(task ".out", "w", stdout);
    }

    std::cin >> n;
    
    if (n == 2 || n == 3)
    {
        std::cout << "NO";
        return 0;
    }
    
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            ans.pb({i, 2 * i});
        }
        for (int i = n / 2 + 1; i <= n; i++)
        {
            ans.pb({i, 2 * (i - n / 2) - 1});
        }
    }
    else
    {
        int m = n - 1;
        for (int i = 1; i <= m / 2; i++)
        {
            ans.pb({i, 2 * i});
        }
        for (int i = m / 2 + 1; i <= m; i++)
        {
            ans.pb({i, 2 * (i - m / 2) - 1});
        }
        ans.pb({n, n});
    }

    std::cout << "YES\n";

    return 0;
}
