#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int arr[7];
        for (int i = 0; i < 7; i++) {
            cin >> arr[i];
        }
        // Sort to find the maximum element
        sort(arr, arr + 7);
        // Negate the 6 smallest elements (keep the largest)
        for (int i = 0; i < 6; i++) {
            arr[i] = -arr[i];
        }
        // Calculate sum
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}