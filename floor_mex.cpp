#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int k = 1; k <= n; k++) cin >> a[k];

        vector<int> diff(n + 2, 0);

        for (int k = 1; k <= n; k++) {
            long long lo = (long long)a[k] * k;
            long long hi = (long long)(a[k] + 1) * k - 1;

            if (lo > n - 1) continue;
            long long l = lo;
            long long r = min(hi, (long long)(n - 1));

            diff[l] += 1;
            diff[r + 1] -= 1;
        }

        vector<int> result;
        int cur = 0;
        for (int y = 0; y < n; y++) {
            cur += diff[y];
            if (cur == 0) result.push_back(y);
        }

        cout << result.size() << "\n";
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i] << " \n"[i + 1 == result.size()];
        }
        if (result.empty()) cout << "\n";
    }
    return 0;
}
