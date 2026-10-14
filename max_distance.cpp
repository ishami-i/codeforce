#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    long long max_distance = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++){
                long long dx = x[i] - x[j];
                long long dy = y[i] - y[j];
                    
                long long distance = dx * dx + dy * dy;
                max_distance = max(max_distance, distance);
        }
    }
    cout << max_distance << '\n';
    return 0;
}
