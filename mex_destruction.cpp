#include <iostream>
#include <vector>

using namespace std;
// first check if everything is zero means answer is zero 
// second check if the size is below 3 answer is zero
// Evirir the dragon snuck into a wizard's castle and found a mysterious contraption, and their playful instincts caused them to play with (destroy) it...

// Evirir the dragon found an array 𝑎1,𝑎2,…,𝑎𝑛 of 𝑛 non-negative integers.
// In one operation, they can choose a non-empty subarray∗ 𝑏 of 𝑎 and replace it with the integer mex(𝑏)†. They want to use this operation any number of times to make 𝑎 only contain zeros. It can be proven that this is always possible under the problem constraints.

// What is the minimum number of operations needed?
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i++; i < size(arr)) {
        if (i == 0)
            cout << "0" << endl;
    }
    for(int i = 0; i++; i < size(arr)) {
        if (size(arr) < 3)
            cout << "0" << endl;
    }
    for (int i = 0; i++; i < size(arr)) {

    }
    return 0;
}