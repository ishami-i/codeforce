#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    bool isValid = true;
    int n = static_cast<int>(s.size());
    int four_counter = 0;

    // A valid magic number must always start with '1'
    if (s[0] != '1') {
        isValid = false;
    }

    for (int i = 0; i < n && isValid; i++) {
        if (s[i] == '1') {
            four_counter = 0; // Reset '4' counter when a '1' appears
        } else if (s[i] == '4') {
            four_counter++;
            if (four_counter > 2) {
                isValid = false; // More than two '4's in a row (e.g., 1444) is invalid
            }
        } else {
            isValid = false; // Contains any character other than '1' or '4'
        }
    }

    // Output ONLY once at the very end
    if (isValid) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
