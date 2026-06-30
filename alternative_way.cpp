#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        bool ok = false;

        // -------------------------------
        // Method 1: Alternating +/-1
        // -------------------------------
        vector<long long> c = a;

        if (c == b) {
            ok = true;
        } else {
            int l = -1;
            for (int i = 0; i < n; i++) {
                if (c[i] != b[i]) {
                    l = i;
                    break;
                }
            }

            if (l != -1) {
                for (int i = l; i < n; i++) {
                    if ((i - l) % 2 == 0)
                        c[i]++;
                    else
                        c[i]--;
                }

                if (c == b)
                    ok = true;
            }
        }

        // -------------------------------
        // Method 2: Adjacent difference
        // -------------------------------
        if (!ok) {
            vector<long long> d = a;

            for (int i = 0; i < n - 1; i++) {
                long long diff = b[i] - d[i];
                d[i] += diff;
                d[i + 1] -= diff;
            }

            if (d[n - 1] == b[n - 1])
                ok = true;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}