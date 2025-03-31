const int pad = 1000058;

int n, m;
int pre[pad];
pair<int, int> a[pad];
vector<int> tmp, ans;
int maxx = 0;

void backtrack(int i, int sum, int val) {
    if (sum > m) return;
    if (i > n) {
        if (val > maxx) {
            maxx = val;
            ans = tmp;
        }
        return;
    }
    
    if (sum + a[i].first <= m && val + a[i].second + pre[i] >= maxx) {
        tmp.push_back(1);
        backtrack(i + 1, sum + a[i].first, val + a[i].second);
        tmp.pop_back();
    }
    
    if (val + pre[i] >= maxx) {
        tmp.push_back(0);
        backtrack(i + 1, sum, val);
        tmp.pop_back();
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen("KSACK1.inp", "r")) {
        freopen("KSACK1.inp", "r", stdin);
        freopen("KSACK1.out", "w", stdout);
    }
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    pre[n] = a[n].second;
    for (int i = n-1; i >= 1; i--) {
        pre[i] = pre[i+1] + a[i].second;
    }
    
    backtrack(1, 0, 0);
    
    cout << maxx << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == 1) {
            cout << i + 1 << " ";
        }
    }
}