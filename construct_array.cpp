#include <iostream>
#include <vector>

using namespace std;

int main() {
    // read integer n as input
    int t;
    cin >> t;
    while (t--) {
            int n;
            cin >> n;
            if (n == 1) {
                cout << 1 << endl;
                continue;
            }
            if (n == 2) {
                cout << 1 << " " << 2 << endl;
                continue;
            }
            vector<int> arr(n);
            vector<int> arr_sum(n-1);
            for (int i = 0; i < n; i++) {
                int element = i + 1;
                while (true) {
                bool is_duplicate = false;
                for (int j = 0; j < i; j++) {
                    if (arr[j] == element) {
                    is_duplicate = true;
                    break;
                    }
                }
                for (int j = 0; j < i - 1; j++) {
                    if (arr_sum[j] == element) {
                    is_duplicate = true;
                    break;
                    }
                }
                if (!is_duplicate) {
                    arr[i] = element;
                    if (i > 0) {
                    arr_sum[i - 1] = arr[i] + arr[i - 1];
                    }
                    break;
                }
                element++;
                }
            }
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
    }
    return 0;
}