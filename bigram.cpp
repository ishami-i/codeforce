#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--) {
        int k;
        cin >> k;

        vector<int> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        // check if there is arr[i] with 3 items or if there is two arr[i] with 2 or more 
        if (any_of(arr.begin(), arr.end(), [](int x) { return x >= 3; }) || count_if(arr.begin(), arr.end(), [](int x) { return x >= 2; }) >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}