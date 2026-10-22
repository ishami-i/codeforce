#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 1; i <= n; i++) {
        int a = f[i];      
        int b = f[a];      
        int c = f[b];      

        if (c == i) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

