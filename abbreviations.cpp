#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // get every starting letter from the n words into a set
        unordered_set<char> letters;
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            letters.insert(toupper(word[0]));
        }

        // get the m abbreviations, and check each one against the letter set
        bool ok = true;
        for (int i = 0; i < m; i++) {
            string abbr;
            cin >> abbr;
            for (char c : abbr) {
                if (letters.find(c) == letters.end()) {
                    ok = false; // this abbreviation uses a letter we never have
                }
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}