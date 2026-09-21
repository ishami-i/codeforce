#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming speed
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // STEP 1: Validity Check
        // The number of unique minimums 'k' must be between n and 2n - 1.
        // If it's outside this mathematical bound, a valid matrix cannot exist.
        if (k < n || k > 2 * n - 1) {
            cout << -1 << "\n";
            continue;
        }

        // STEP 2: Calculate overlap and subgrid size
        // 'm' is the number of cells on the main diagonal that must simultaneously 
        // act as both the row minimum and column minimum to achieve exactly 'k' unique elements.
        int m = 2 * n - k;
        // 'L' is the dimension of the remaining bottom-right block to be filled.
        int L = n - m + 1;

        // Initialize an n x n matrix with zeros
        vector<vector<int>> mat(n, vector<int>(n, 0));

        // Pointers/counters for our three number pools:
        int diag_counter = 1;               // Pool 1: Tiny numbers for the upper-left diagonal (1, 2, 3...)
        int block_start = m;                // Pool 2: Mid-range numbers used to fill the bottom-right block
        int border_counter = m + L * L;     // Pool 3: Huge numbers used to fill the remaining rows/columns securely

        // STEP 3: Shelling / Border filling for the first (m - 1) rows and columns
        for (int i = 0; i <= m - 2; i++) {
            // Place a guaranteed minimum on the diagonal
            mat[i][i] = diag_counter++;
            
            // Fill the rest of row 'i' with large numbers so they don't interfere with the minimum
            for (int j = i + 1; j < n; j++) mat[i][j] = border_counter++;
            
            // Fill the rest of column 'i' with large numbers for the same reason
            for (int r = i + 1; r < n; r++) mat[r][i] = border_counter++;
        }
        
        // STEP 4: Fill the remaining L x L block at the bottom right
        // We fill this grid sequentially starting from 'block_start'.
        // This ensures the top-left cell of this subgrid (mat[m-1][m-1]) becomes 
        // the shared minimum for all remaining rows and columns.
        int val = block_start;
        for (int r = m - 1; r < n; r++) {
            for (int c = m - 1; c < n; c++) {
                mat[r][c] = val++;
            }
        }
                
        // STEP 5: Fast Output Formatting
        // Reserve memory in a string to avoid reallocation overhead during string additions
        string out;
        out.reserve((size_t)n * n * 7);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out += to_string(mat[i][j]);
                out += (j == n - 1) ? '\n' : ' '; // Newline at the end of the row, space otherwise
            }
        }
        cout << out; // Print the entire matrix configuration at once
    }
    return 0;
}
