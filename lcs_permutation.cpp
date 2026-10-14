// this way got the Time limit exceeded on test 27
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int longest(const vector<int>& a, const vector<int>& b, int n, int m) {
//     if (n == 0 || m == 0) {
//         return 0;
//     }
    
//     if (a[n - 1] == b[m - 1]) {
//         return 1 + longest(a, b, n - 1, m - 1);
//     } 
//     else {
//         return max(longest(a, b, n - 1, m), longest(a, b, n, m - 1));
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     vector<int> b(n);

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }

//     for (int i = 0; i < n; i++) {
//         cin >> b[i];
//     }

//     cout << longest(a, b, n, n) << endl;

//     return 0;
// }
// Memory limit exceeded on test 52
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][n] << "\n";

    return 0;
}
