#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coin(n);
    int total_sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
        total_sum += coin[i];
    }
    sort(coin.rbegin(), coin.rend());

    int counter = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += coin[i];
        total_sum -= coin[i];
        counter++;
        if(sum > total_sum) {
            cout << counter <<'\n';
            return 0;
        }
    }
    return 0;
}
