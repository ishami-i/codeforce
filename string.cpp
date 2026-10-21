#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int counter = 0;
        for(char c : s) {
            if(c == '1') {
                counter++;
            }   
        }
        cout << counter << '\n';
    }
    return 0;
}
