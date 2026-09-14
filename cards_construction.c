#include <stdio.h>
#include <math.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0; 
    
    while(t--) {
        int n;
        if (scanf("%d", &n) != 1) break; 
        
        int pyramid_built = 0;
        while(n >= 2) {
            long long h = floor((sqrt(24.0 * n + 1.0) - 1.0) / 6.0);
            long long cards_used = (3 * h * h + h) / 2;
            n -= cards_used;
            pyramid_built++;
        }
        printf("%d\n", pyramid_built); 
    }
    return 0;
}

