#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // freq[value] = how many numbers can reach this value
        unordered_map<int, int> freq;

        // costSum[value] = total operations needed
        unordered_map<int, int> costSum;

        for (int x : arr) {

            unordered_map<int, int> visited;

            int steps = 0;
            int cur = x;

            while (true) {

                // avoid duplicates
                if (!visited.count(cur)) {
                    visited[cur] = steps;

                    freq[cur]++;
                    costSum[cur] += steps;
                }

                if (cur == 1)
                    break;

                if (cur % 2 == 1)
                    cur++;
                else
                    cur /= 2;

                steps++;
            }
        }

        int answer = INT_MAX;

        for (auto &p : freq) {
            int value = p.first;

            // reachable by all elements
            if (freq[value] == n) {
                answer = min(answer, costSum[value]);
            }
        }

        cout << answer << endl;
    }

    return 0;
}
