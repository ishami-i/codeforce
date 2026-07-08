#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    while(q--) {
        int y_1, x_1, y_2, x_2;
        cin >> y_1 >> x_1 >> y_2 >> x_2;

        // counting trees in grid
        // pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[1-i][j - 1] + grid[i][j] for general
        // pre
    }
    return 0;
}
