#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        map<int,int> freq;
        for (int x : a) freq[x]++;

        // max-heap on (count, value)
        priority_queue<pair<int,int>> pq;
        for (auto &p : freq) pq.push({p.second, p.first});

        long long sum = 0;
        int last = -1; // -1 = no card played yet (values are >=1, safe sentinel)

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();

            if (top.second != last) {
                // safe to play the most plentiful value
                sum += top.second;
                last = top.second;
                if (--top.first > 0) pq.push(top);
            } else {
                // most plentiful value repeats last card -> need an alternative
                if (pq.empty()) {
                    // no alternative anywhere -> forced repeat, then shield triggers, stop
                    sum += top.second;
                    break;
                }
                auto alt = pq.top(); pq.pop();
                sum += alt.second;
                last = alt.second;
                if (--alt.first > 0) pq.push(alt);
                pq.push(top); // put the original back for a later turn
            }
        }

        cout << sum << "\n";
    }
    return 0;
}
