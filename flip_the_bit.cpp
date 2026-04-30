#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int n, m, b, a;
    cin >> n >> m >> b >> a;

    if (gcd(a, n) == 1 && gcd(b, m) == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}