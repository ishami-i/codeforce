#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int counter = 0;
    
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m += 1;
        }
        counter++;
    }
    counter += (n - m);
    
    cout << counter << '\n';
    
    return 0;
}
