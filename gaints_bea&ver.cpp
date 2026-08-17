#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        long long Hb = (long long)a[0] + n - 1; // hits needed to defeat Bea
        long long Hv = (long long)b[0] + m - 1; // hits needed to defeat Ver

        // Bea goes first, so on a tie Bea's hit lands first -> Bea wins
        cout << (Hv <= Hb ? 1 : 2) << '\n';
    }
    return 0;
}