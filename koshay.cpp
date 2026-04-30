#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // Check if both are odd (not divisible by 2)
        if (x % 2 != 0 && y % 2 != 0) {
            cout << "NO" << endl;
        } else {
            // If one is even, or both are even
            cout << "YES" << endl;
        }
    }
    
    return 0;
}