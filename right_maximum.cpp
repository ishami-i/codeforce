#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    // read the size of array
    cin >> n;
    // read the array elements
    vector<int> arr(n);

    int max_element = 0;
    int counter = 0;
    // create loop that read the array from a[n-1] to a[0], and find the maximum element then remove the elements from maximum to the end of array, and count the number of times we remove the elements until the array is empty
    if (arr.size() > 0) {
        for (int i = n -1; i >= 0; i--) {
         vector<int>::iterator maxIter = std::max_element(arr.begin(), arr.end()); 
         int maxIndex = std::distance(arr.begin(), maxIter);
         arr.erase(arr.begin() + maxIndex, arr.end());
        counter++;
        }
        return counter;
    }
    return 0;
}