#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
    cin >> n;
    
    int odds = 0;
    int evens_mod_4_0 = 0;
    int evens_mod_4_2 = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        if (a % 2 != 0) {
            odds++;
        } else {
            if (a % 4 == 0) {
                evens_mod_4_0++;
            } else {
                evens_mod_4_2++;
            }
        }
    }
    
    int ans = max({odds, evens_mod_4_0, evens_mod_4_2});
    cout << ans << '\n';
    }
    
    return 0;
}

