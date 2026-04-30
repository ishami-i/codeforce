#include <iostream>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

int main() {
    cout.imbue(locale("en_US.UTF-8"));
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // checking if every element is p or . only for whole array then return YES
    bool all_p_or_dot = all_of(arr.begin(), arr.end(), [](int x) {
        return x == 'p' || x == '.';
    });
    if (all_p_or_dot) {
        cout << "YES" << endl;
    } else {
        // checking the condition for every element to check for permutation exist or not 
        for(int i = 0; i < n; i++) {
            if (arr[i] == 'p') {
                vector<bool> seen(i + 1, false);
                for (int j = 0; j <= i; j++) {
                    if (arr[j] < '1' || arr[j] > '9' || seen[arr[j] - '1']) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    seen[arr[j] - '1'] = true;
                }
            } else if (arr[i] == 'S') {
                vector<bool> seen(n - i, false);
                for (int j = i; j < n; j++) {
                    if (arr[j] < '1' || arr[j] > '9' || seen[arr[j] - '1']) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    seen[arr[j] - '1'] = true;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}