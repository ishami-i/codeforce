#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int rounds = 0;

        while (!(a == b || a == c || b == c)) {
            int mx = max({a, b, c});
            int mn = min({a, b, c});

            // decrement whichever variable holds the max
            if (a == mx) a--;
            else if (b == mx) b--;
            else c--;

            // increment whichever variable holds the min
            if (a == mn) a++;
            else if (b == mn) b++;
            else c++;

            rounds++;
        }

        cout << rounds << '\n';
    }

    return 0;
}
