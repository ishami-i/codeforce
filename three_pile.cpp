#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        
        // first diff
        int first_diff = abs(a - b);
        
        // second diff
        a = a + c;
        int second_diff = abs(a - b);
        
        cout << max(first_diff, second_diff) << '\n';
    }
    return 0;
}
