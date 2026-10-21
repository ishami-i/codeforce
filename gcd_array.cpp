#include <iostream>
#include <algorithm> // 1. Fixed spelling

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            int l, r, k;
            cin >> l >> r >> k;
            
            // Case 1: If there is only one element in the range
            if (l == r) {
                if (l == 1) {
                    cout << "NO\n"; // GCD of {1} is 1, which is not > 1
                } else {
                    cout << "YES\n"; // GCD of {l} where l > 1 is already > 1
                }
                continue;
            }
            
            // Case 2: Count the number of odd numbers in the range [l, r]
            // Odd numbers prevent the total GCD from being divisible by 2.
            // We need to eliminate them by multiplying them with an even number.
            int total_elements = r - l + 1;
            int odd_count = total_elements / 2;

            // If both boundaries are odd, there's one extra odd number
            if (l % 2 != 0 && r % 2 != 0) {
                odd_count++;
            }
            
            // Each operation (k) can eliminate exactly one odd number 
            // by multiplying it with an adjacent even number.
            if (k >= odd_count) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}

