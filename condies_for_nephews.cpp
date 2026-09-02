#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        if((n % 3) == 0) {
            cout << 0 << '\n';
        } else {
            int reminder = n % 3;
            int candies_to = 3 - reminder;
            cout << candies_to << '\n';
        }
    }
    return 0;
}