#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long c;

        cin >> n >> c;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Required by the statement
        reverse(a.begin(), a.end());

        vector<vector<long long>> dp(n, vector<long long>(n));

        // Base case: intervals of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = a[i] - c;
        }

        // Build DP by increasing interval length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                dp[i][j] = -(1LL << 60);

                // Split into two parts
                for (int k = i; k < j; k++) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + dp[k + 1][j]);
                }

                // Pair the endpoints
                long long gain = max(a[i], a[j]) - c;

                if (len == 2) {
                    dp[i][j] = max(dp[i][j], gain);
                } else {
                    dp[i][j] = max(dp[i][j],
                                   dp[i + 1][j - 1] + gain);
                }
            }
        }

        cout << dp[0][n - 1] << '\n';
    }

    return 0;
}