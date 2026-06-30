#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        // read an array of two integers
        vector<int> arr(2);
        cin >> arr[0] >> arr[1];

        int x = arr[0];
        int y = arr[1];

        if (x % y == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}