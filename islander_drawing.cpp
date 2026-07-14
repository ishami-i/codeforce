#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string line;
        cin >> line;

        int max_streak = 0;
        int streak = 0;

        for (char c : line) {
            if (c == '#') {
                streak++;
                max_streak = max(max_streak, streak);
            } else {
                streak = 0;
            }
        }

        cout << (max_streak + 1) / 2 << '\n';
    }

    return 0;
}