#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> div6;
        vector<int> div2;
        vector<int> div3;
        vector<int> others;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x % 6 == 0) {
                div6.push_back(x);
            }
            else if (x % 2 == 0) {
                div2.push_back(x);
            }
            else if (x % 3 == 0) {
                div3.push_back(x);
            }
            else {
                others.push_back(x);
            }
        }

        // Print in optimal order

        for (int x : div6) {
            cout << x << " ";
        }

        for (int x : div2) {
            cout << x << " ";
        }

        for (int x : others) {
            cout << x << " ";
        }

        for (int x : div3) {
            cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}