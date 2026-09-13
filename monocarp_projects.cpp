#include <iostream>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        
        long long himself = 0;
        long long diff = y - x; 
        
        while (x <= diff && k > 0) {
            himself += (diff % x);
            x++;
            k--;
        }
        
        if (k > 0) {
            himself += (k * diff);
        }
        
        cout << himself << '\n';
    }
    return 0;
}
