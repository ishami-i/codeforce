#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> characters;
vector<vector<int>> adj;
vector<bool> visited;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    characters.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n, false);
    long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            total_sum += dfs(i);
        }
    }

    cout << total_sum << "\n";

    return 0;
}
