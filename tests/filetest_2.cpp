#include <iostream>
using namespace std;

const int N = 100005;
int a[N], cnt[N];

int main() {
    int n;
    cin >> n;
    for (int .i = 0; i < n; i++) cin >> a[i];

    long long res = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cnt[a[r]]++;
        while (cnt[a[r]] > 1) {
            cnt[a[l]]--;
            l++;
        }
        res += (r - l + 1);
    }
    cout << res << endl;
    return 0;
}