#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long n, k;
        cin >> n >> k;
        
        long sum = 0;
        // for the more than one withdraws
        long small_withdraws = (2 * (k - 1));
        
        // for the last one
        long last_withdraw = pow(2, (n - (k - 1)));
        
        sum = small_withdraws + last_withdraw;
        cout << sum << '\n';
    }
    return 0;
}
