#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // build run-length encoding
        vector<char> runChar;
        vector<int> runLen;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            runChar.push_back(s[i]);
            runLen.push_back(j - i);
            i = j;
        }

        int m = runChar.size();
        int C = m;
        int maxReduction = 0;

        for (int j = 0; j < m; j++) {
            if (runLen[j] == 1 && j != 0 && j != m - 1) {
                int reduction = (runChar[j - 1] == runChar[j + 1]) ? 2 : 1;
                maxReduction = max(maxReduction, reduction);
            }
        }

        cout << (C - maxReduction) << '\n';
    }

    return 0;
}
