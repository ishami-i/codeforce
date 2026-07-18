#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
        }

        if (n % 2 == 0 && sum % 4 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}