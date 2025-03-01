#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
stack<int> st;
int cnt = 0, ans = 0;

void logic() {
    cin >> s;  
    for (char c : s) {
        if (c == '0') {
            st.push(0);
        }
        else { // c == '1'
            if (!st.empty()) {
                st.pop();
                ++cnt;
            }
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
    }
    ans = max(ans, cnt); // Cập nhật lần cuối nếu còn `cnt`
    cout << 2 * ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    logic();
    return 0;
}