#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        
        int counter_zero = 0;
        int counter_one = 0;
        vector<int> array(n);
        
        for(int i = 0; i < n; i++) {
            cin >> array[i];
            if(array[i] == 0) {
                counter_zero++;
            } else {
                counter_one++;
            }
        }
        
        int first = array[0];
        int last = array[n-1];
        
        if (first == 0 && last == 0) {
            cout << 0 << '\n';
        } 
        else if (first == 1 && last == 1) {
            if (counter_zero < 2) {
                cout << -1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        } 
        else {
            if (counter_zero > 1) {
                cout << 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}
