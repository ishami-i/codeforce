#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
           int n;
           cin >> n;
           
           string s;
           cin >> s;
           
           int number_a = 0;
           int number_b = 0;
           
           for(int i = 0; i < n; i++) {
               if(s[i] == 'a') {
                   number_a++;
               } else {
                   number_b++;
               }
           }
           if(number_a == 0 || number_b == 0) {
               cout << "-1" << '\n';
           } else {
               cout << abs(number_a - number_b) << '\n';
           }
        }
    }
    return 0;
}