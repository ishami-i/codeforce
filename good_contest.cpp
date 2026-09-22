#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> array(3);
        for(int i = 0; i < 3; i++) {
            cin >> array[i];
        }
        int min_weak = 0;
        for(int i = 0; i < 3; i++) {
            int weak = n - array[i];
            min_weak = max(min_weak, weak);
        }
        cout << min_weak << '\n';
    }
    return 0;
}
