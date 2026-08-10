#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector> 
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        vector<int> numbers(3);
        for(int i = 0; i < 3; i++) {
            cin >> numbers[i];
        }
        
        sort(numbers.begin(), numbers.end());
        int a = numbers[0];
        int b = numbers[1];
        int c = numbers[2];
        
        if(a == b && b == c) {
            cout << 0 << '\n';
            continue; 
        }
        int min_range = c - a;
        
        int new_number = a + b;
        vector<int> option = {a, b, new_number};
        sort(option.begin(), option.end());
        
        int range = option[2] - option[0];
        min_range = min(min_range, range);
        
        cout << min_range << '\n';
    }
    return 0;
}
