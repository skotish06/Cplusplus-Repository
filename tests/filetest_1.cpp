#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Đọc dữ liệu từ file

    int n;
    cin >> n;

    // Tạo mảng dp: dp[i] là số cách phân tích số i
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    // Quy hoạch động
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j] += dp[j - i];
        }
    }

    // Ghi kết quả ra file
    cout << dp[n] << endl;

    // Đóng file

    return 0;
}