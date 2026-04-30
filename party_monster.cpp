#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        // count the '(' and ')'

        // Count opening parentheses
        int openCount = count(s.begin(), s.end(), '(');

        // Count closing parentheses
        int closeCount = count(s.begin(), s.end(), ')');        

        if (openCount != closeCount) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }

    }
    return 0;
}