#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Global variables for the graph
vector<int> characters;
vector<vector<int>> adj;
vector<bool> visited;

// DFS to traverse the connected component and find the minimum value character
int dfs(int node) {
    visited[node] = true;
    int min_val = characters[node];
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            min_val = min(min_val, dfs(neighbor));
        }
    }
    return min_val;
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    characters.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    // Build the adjacency list (using 0-based indexing for convenience)
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert 1-based input to 0-based
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n, false);
    long long total_sum = 0;

    // Iterate through all characters
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // If the node is unconnected, DFS returns its own value.
            // If it is in a group, DFS returns the minimum of that entire group.
            total_sum += dfs(i);
        }
    }

    cout << total_sum << "\n";

    return 0;
}
