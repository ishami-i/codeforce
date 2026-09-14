#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        long long n; 
        cin >> n;

        int pyramids_built = 0;
        /* 
           ORIGINAL PATTERN:
           h = 1 => (1)3 - 1             = 2
           h = 2 => (2+1)3 - 2           = 7
           h = 3 => (3+2+1)3 - 3         = 15
           h = 4 => (4+3+2+1)3 - 4       = 26
           
           DERIVED FORWARD FORMULA:
           f(h) = 3 * [h(h+1)/2] - h
           f(h) = (3h^2 + h) / 2
           
           DERIVED INVERSE FORMULA:
           y = (3h^2 + h) / 2  =>  3h^2 + h - 2y = 0
           Using Quadratic Formula: h = (-b + sqrt(b^2 - 4ac)) / 2a
           f^-1(y) = (sqrt(24y + 1) - 1) / 6
        */

        // Keep building pyramids as long as we have at least 2 cards (minimum needed for h=1)
        while (n >= 2) {
            // Find the maximum height h we can build with the current number of cards
            long long h = floor((sqrt(24.0 * n + 1.0) - 1.0) / 6.0 + 1e-9);
            
            // Calculate how many cards this specific pyramid consumes
            long long cards_used = (3 * h * h + h) / 2;
            
            // Subtract the used cards from our total
            n -= cards_used;
            
            // Increment our constructed pyramid count
            pyramids_built++;
        }

        cout << pyramids_built << '\n';
    }
    return 0;
}
