#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    // Store data column by column: columns[m][n]
    vector<vector<long long>> columns(m, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> columns[j][i]; // Read directly into column lists
        }
    }

    long long total_chips = 0;

    // Process each column independently
    for (int j = 0; j < m; j++) {
        // Sort the current column in ascending order
        sort(columns[j].begin(), columns[j].end());

        // Calculate total absolute differences for this column in O(n)
        for (int i = 0; i < n; i++) {
            total_chips += columns[j][i] * (2LL * i - n + 1);
        }
    }

    cout << total_chips << '\n';
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

