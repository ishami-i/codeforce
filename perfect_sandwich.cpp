#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        
        if(b > a) {
            cout << "-1" << '\n';
        } else {
            // Explicitly use std::lcm to prevent compiler ambiguity
            cout << std::lcm(a, b) << '\n'; 
        }
    }
    return 0;
}
