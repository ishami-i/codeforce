#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int m = n - k; // number of blocks needed

        if (k < 0 || k > n - 1 || (m == 1 && n != 1)) {
            cout << -1 << '\n';
            continue;
        }

        int a = (m + 1) / 2; // blocks of the "first" color
        int b = m / 2;        // blocks of the "second" color

        int Sx = n / 2;       // total length for first color
        int Sy = n - Sx;      // total length for second color

        if (Sx < a) {
            Sx = a;
            Sy = n - a;
        } else if (Sy < b) {
            Sy = b;
            Sx = n - b;
        }

        string s;
        s.reserve(n);

        int firstBlockLenX = (a > 0) ? Sx - (a - 1) : 0; // remaining a-1 blocks get length 1
        int firstBlockLenY = (b > 0) ? Sy - (b - 1) : 0; // remaining b-1 blocks get length 1

        bool usedFirstX = false, usedFirstY = false;
        char colorX = '0', colorY = '1';

        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                // color X block
                int len = (!usedFirstX) ? firstBlockLenX : 1;
                usedFirstX = true;
                s.append(len, colorX);
            } else {
                // color Y block
                int len = (!usedFirstY) ? firstBlockLenY : 1;
                usedFirstY = true;
                s.append(len, colorY);
            }
        }

        cout << s << '\n';
    }
    return 0;
}