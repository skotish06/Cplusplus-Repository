#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>

using namespace std;
const int N = 1e6 + 9;
int n;
int a[N];
int cnt = 0; // Biến toàn cục để đếm số lượng '1'

void ql(int i) {
    if (i > n) {
        for (int j = 1; j <= n; ++j) {
            cout << a[j];
        }
        cout << '\n';
        return;
    }

    // Chọn số 0
    a[i] = 0;
    ql(i + 1);

    // Chọn số 1 (chỉ khi chưa vượt quá 2 lần)
    if (cnt < 2) {
        a[i] = 1;
        cnt++;  // Tăng biến đếm '1'
        ql(i + 1);
        cnt--;  // Quay lui, giảm biến đếm '1'
    }
}

void logic() {
    cin >> n;
    ql(1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    logic();

    return 0;
}
