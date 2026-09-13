#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k < n || k > 2 * n - 1) {
            cout << -1 << "\n";
            continue;
        }

        int m = 2 * n - k;
        int L = n - m + 1;

        vector<vector<int>> mat(n, vector<int>(n, 0));

        int diag_counter = 1;
        int block_start = m;
        int border_counter = m + L * L;

 
        for (int i = 0; i <= m - 2; i++) {
            mat[i][i] = diag_counter++;
            for (int j = i + 1; j < n; j++) mat[i][j] = border_counter++;
            for (int r = i + 1; r < n; r++) mat[r][i] = border_counter++;
        }
        
        int val = block_start;
        for (int r = m - 1; r < n; r++)
            for (int c = m - 1; c < n; c++)
                mat[r][c] = val++;
                
        string out;
        out.reserve((size_t)n * n * 7);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out += to_string(mat[i][j]);
                out += (j == n - 1) ? '\n' : ' ';
            }
        }
        cout << out;
    }
    return 0;
}
