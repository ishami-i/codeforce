#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        bool ok = true;
        
        for(int i = 0; i < n - 1; i++) {
            if(isdigit(s[i]) && s[i] > s[i + 1]) {
                ok = false;
                break;
            } else if(isalpha(s[i]) && isdigit(s[i + 1])) {
                ok = false;
                break;
            } else if(isalpha(s[i]) && s[i] > s[i + 1]) {
                ok = false;
                break;
            }
        }
        
        if(ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
