#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> levelingPoints(n);
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            levelingPoints[i] = sum / (i + 1);
        }
        
        // Print the leveling array
        for(int i = 0; i < n; i++) {
            cout << levelingPoints[i];
            if(i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
