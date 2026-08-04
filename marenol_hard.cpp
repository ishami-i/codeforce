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

        // Reachability + op-count argument:
        // 001<->100 fires only when middle='0' and ends differ.
        // 110<->011 fires only when middle='1' and ends differ.
        // => whenever s[i] != s[i+2] we can ALWAYS swap them (1 operation),
        //    using whichever rule matches the middle character.
        // i and i+2 share parity, so odd-indexed and even-indexed positions
        // form two independent groups, each freely permutable by adjacent
        // swaps (in the subsequence sense). Each such adjacent swap = 1 op.
        //
        // Reachable iff count of '1' matches in each group.
        // Minimum ops = for each group, match the i-th '1' in a's group to
        // the i-th '1' in b's group (indistinguishable 1s => this greedy
        // pairing is optimal) and sum |posA[i] - posB[i]| (positions given
        // as 0-indexed ranks WITHIN the group's subsequence).

        vector<int> posOddA, posEvenA, posOddB, posEvenB;
        int oddIdx = 0, evenIdx = 0; // rank within each group's subsequence

        for (int i = 0; i < n; i++) {
            bool oddPos = ((i + 1) % 2 == 1); // 1-indexed position
            if (oddPos) {
                if (a[i] == '1') posOddA.push_back(oddIdx);
                if (b[i] == '1') posOddB.push_back(oddIdx);
                oddIdx++;
            } else {
                if (a[i] == '1') posEvenA.push_back(evenIdx);
                if (b[i] == '1') posEvenB.push_back(evenIdx);
                evenIdx++;
            }
        }

        if (posOddA.size() != posOddB.size() || posEvenA.size() != posEvenB.size()) {
            cout << -1 << '\n';
            continue;
        }

        long long ops = 0;
        for (size_t i = 0; i < posOddA.size(); i++) {
            ops += llabs((long long)posOddA[i] - (long long)posOddB[i]);
        }
        for (size_t i = 0; i < posEvenA.size(); i++) {
            ops += llabs((long long)posEvenA[i] - (long long)posEvenB[i]);
        }

        cout << ops << '\n';
    }
    return 0;
}
