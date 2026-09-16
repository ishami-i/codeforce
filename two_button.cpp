#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int counter = 0;
    
    // Work backwards from m to n
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2; // Reverse of multiplying by 2
        } else {
            m += 1; // Reverse of subtracting 1
        }
        counter++;
    }
    
    // If n is now greater than or equal to m, 
    // the only way to bridge the gap is by subtracting 1 sequentially.
    counter += (n - m);
    
    cout << counter << '\n';
    
    return 0;
}
