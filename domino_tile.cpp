#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 998244353;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
 
    long long MOD = 998244353;
 
    if (n == 2) {
        int q_count = 0;
        if (s[0] == '?') q_count++;
        if (s[1] == '?') q_count++;
        cout << power(2, q_count) << "\n";
        return;
    }
 
    bool even_pattern_0 = true;
    bool even_pattern_1 = true; 
    for (int i = 0; i < n; i += 2) {
        if (s[i] != '?') {
            int expected_0 = (i / 2) % 2;
            if (s[i] - '0' != expected_0) even_pattern_0 = false;
            if (s[i] - '0' != (expected_0 ^ 1)) even_pattern_1 = false;
        }
    }
 
    bool odd_pattern_0 = true;   
    bool odd_pattern_1 = true;  
 
    for (int i = 1; i < n; i += 2) {
        if (s[i] != '?') {
            int expected_0 = ((i - 1) / 2) % 2;
            if (s[i] - '0' != expected_0) odd_pattern_0 = false;
            if (s[i] - '0' != (expected_0 ^ 1)) odd_pattern_1 = false;
        }
    }
 
    long long ways_even = 0;
    if (even_pattern_0) ways_even++;
    if (even_pattern_1) ways_even++;
 
    long long ways_odd = 0;
    if (odd_pattern_0) ways_odd++;
    if (odd_pattern_1) ways_odd++;
 
    long long total_ways = (ways_even * ways_odd) % MOD;
    cout << total_ways << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
