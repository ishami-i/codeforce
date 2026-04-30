#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        int x;
        std::cin >> x;
        std::cout << x + 1 << '\n';
    }
    return 0;
}