#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest(const vector<int>& a, const vector<int>& b, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }
    
    if (a[n - 1] == b[m - 1]) {
        return 1 + longest(a, b, n - 1, m - 1);
    } 
    else {
        return max(longest(a, b, n - 1, m), longest(a, b, n, m - 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << longest(a, b, n, n) << endl;

    return 0;
}
