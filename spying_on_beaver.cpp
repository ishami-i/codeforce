#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> par(n + 1, 0);
        for (int i = 2; i <= n; i++) cin >> par[i];

        int m;
        cin >> m;
        vector<int> dam(m);
        vector<char> isDam(n + 1, 0);
        for (int i = 0; i < m; i++) {
            cin >> dam[i];
            isDam[dam[i]] = 1;
        }

        // Step 1: mark all vertices on some root-to-dam path (the "Dam Tree")
        vector<char> marked(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int v = dam[i];
            while (v >= 1 && !marked[v]) {
                marked[v] = 1;
                if (v == 1) break;
                v = par[v];
            }
        }

        // Step 2: build Dam Tree adjacency (only marked children)
        vector<vector<int>> dch(n + 1);
        for (int v = 2; v <= n; v++)
            if (marked[v] && marked[par[v]]) dch[par[v]].push_back(v);

        // Step 3: DP, processing vertices n..1 (parent index < child index)
        const long long INF = (long long)1e18;
        vector<long long> f(n + 1, 0), g(n + 1, 0);
        for (int v = n; v >= 1; v--) {
            if (!marked[v]) continue;
            if (dch[v].empty()) {
                // leaf of Dam Tree is always a dam
                f[v] = 0;
                g[v] = INF;
            } else {
                long long sumT = 0, bestSaving = LLONG_MIN;
                for (int u : dch[v]) {
                    long long T = min(g[u], f[u] + 1);
                    sumT += T;
                    bestSaving = max(bestSaving, T - f[u]);
                }
                if (isDam[v]) {
                    f[v] = sumT;
                    g[v] = INF;
                } else {
                    g[v] = sumT;
                    f[v] = sumT - bestSaving;
                }
            }
        }

        long long k = f[1];
        vector<int> cameras;

        // Step 4: reconstruction (iterative to avoid deep recursion)
        // state 0 = Relaxed(F), state 1 = Strict(G)
        vector<pair<int,int>> stk;
        stk.push_back({1, 0}); // root is always processed in Relaxed state
        while (!stk.empty()) {
            auto [v, state] = stk.back();
            stk.pop_back();
            if (dch[v].empty()) continue;

            if (isDam[v] || state == 1) {
                // all children forced Strict
                for (int u : dch[v]) {
                    if (f[u] + 1 <= g[u]) {
                        cameras.push_back(u);
                        stk.push_back({u, 0});
                    } else {
                        stk.push_back({u, 1});
                    }
                }
            } else {
                // not a dam, Relaxed: exactly one child stays Relaxed (best savings)
                int bestU = -1;
                long long bestSaving = LLONG_MIN;
                for (int u : dch[v]) {
                    long long T = min(g[u], f[u] + 1);
                    long long saving = T - f[u];
                    if (saving > bestSaving) { bestSaving = saving; bestU = u; }
                }
                for (int u : dch[v]) {
                    if (u == bestU) {
                        stk.push_back({u, 0}); // relaxed, no forced camera here
                    } else if (f[u] + 1 <= g[u]) {
                        cameras.push_back(u);
                        stk.push_back({u, 0});
                    } else {
                        stk.push_back({u, 1});
                    }
                }
            }
        }

        sort(cameras.begin(), cameras.end());
        cout << k;
        for (int c : cameras) cout << ' ' << c;
        cout << '\n';
    }
    return 0;
}