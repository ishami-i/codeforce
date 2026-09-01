#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == b && b == c) {
            cout << 0 << '\n';
        } else {
            vector<int> data = {a, b, c};
            sort(data.begin(), data.end());
            
            int range = data[2] - data[0];
            int sum = data[0] + data[1];
            
            int range_2 = sum - data[0];
            
            cout << min(range, range_2) << '\n';
        }
    }
    return 0;
}