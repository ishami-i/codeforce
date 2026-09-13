#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ones = 0, zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 1) ones++;
            else zeros++;
        }

        cout << (ones >= zeros ? "Bessie" : "Elsie") << '\n';
    }

    return 0;
}
