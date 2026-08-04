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
        string a, b;
        cin >> a >> b;

        // Key observation:
        // 001<->100 only fires when the middle char is '0' and the ends differ.
        // 110<->011 only fires when the middle char is '1' and the ends differ.
        // Together: whenever s[i] != s[i+2], we can ALWAYS swap them
        // (pick whichever operation matches the middle character).
        // Since i and i+2 have the same parity, positions of the same
        // parity form an independent group that can be freely permuted
        // (adjacent transpositions of differing elements = bubble sort).
        // So the only invariant is: count of '1' at odd positions and
        // count of '1' at even positions must match between a and b.

        int oddOnesA = 0, evenOnesA = 0;
        int oddOnesB = 0, evenOnesB = 0;

        for (int i = 0; i < n; i++) {
            bool oddPos = ((i + 1) % 2 == 1); // 1-indexed position
            if (oddPos) {
                oddOnesA += (a[i] == '1');
                oddOnesB += (b[i] == '1');
            } else {
                evenOnesA += (a[i] == '1');
                evenOnesB += (b[i] == '1');
            }
        }

        bool ok = (oddOnesA == oddOnesB) && (evenOnesA == evenOnesB);
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
