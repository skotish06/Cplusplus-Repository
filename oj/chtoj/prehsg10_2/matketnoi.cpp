#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPossible(int x, vector<int>& houses, vector<int>& towers) {
    int n = houses.size();
    int m = towers.size();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (abs(houses[i] - towers[j]) <= x) {
            i++;
        } else {
            j++;
        }
    }
    return i == n;
}

int findMinX(vector<int>& houses, vector<int>& towers) {
    sort(houses.begin(), houses.end());
    sort(towers.begin(), towers.end());
    int left = 0, right = 1e18;
    int result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(mid, houses, towers)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> houses(n);
        vector<int> towers(m);
        for (int i = 0; i < n; i++) {
            cin >> houses[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> towers[i];
        }
        cout << findMinX(houses, towers) << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}