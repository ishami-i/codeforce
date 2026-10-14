#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    
    vector<int> time(n);
    for(int i = 0; i < n; i++) {
        cin >> time[i];
    }
    
    sort(time.begin(), time.end());
    
    int counter = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += time[i];
        if(sum > x) {
            cout << counter << '\n';
            return 0;
        }
        counter++;
    }
    cout << counter << '\n'; 
    return 0;
}
