#include <bits/stdc++.h>
using namespace std;
int n, q, a[100005], l[100005], r[100005];
pair<int, int> len[100005], gb[100005];
stack<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen("cpack.inp", "r"))
    {
        freopen("cpack.inp", "r", stdin);
        freopen("cpack.out", "w", stdout);
    }
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        len[i].first = a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            l[i] = 0;
        else
            l[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if (s.empty())
            r[i] = n + 1;
        else
            r[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        len[i].second = (r[i] - l[i] - 1);
    }
    sort(len + 1, len + n + 1);
    for (int i = 1; i <= n; i++)
    {
        len[i].second = max(len[i].second, len[i - 1].second);
    }
    int z;
    for (int i = 1; i <= q; i++)
    {
        cin >> z;
        pair<int, int> y = {z, 1e9};
        int k = upper_bound(len + 1, len + n + 1, y) - len;
        cout << len[k - 1].second << '\n';
    }
}