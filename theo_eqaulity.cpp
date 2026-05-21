#include <iostream>
#include <vector>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int counter = 0;
        
        while (true) {
            bool is_equal = true;
            for (int i = 1; i < n; i++) {
                if (arr[i] != arr[0]) {
                    is_equal = false;
                    break;
                }
            }
            if (is_equal) {
                cout << counter << endl;
                break;
            }
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 1) {
                    arr[i]++;
                    counter++;
                }
            }
            for (int i = 0; i < n; i++) {
                arr[i] /= 2;
            }
            counter++;
        }
    }
    return 0;
}
