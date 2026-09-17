#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> characters(n);
    for(int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    // Read m friendships (pairs of connected characters)
    vector<set<int>> friend_groups;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // reading the connection/friendship pair
        
        int u_idx = -1;
        int v_idx = -1;
        
        // Check which groups u and v belong to
        for(size_t j = 0; j < friend_groups.size(); j++) {
            if(friend_groups[j].count(u)) u_idx = j;
            if(friend_groups[j].count(v)) v_idx = j;
        }
        
        if(u_idx != -1 && v_idx != -1) {
            // Both are already in groups. If they are in different groups, merge them.
            if(u_idx != v_idx) {
                friend_groups[u_idx].insert(friend_groups[v_idx].begin(), friend_groups[v_idx].end());
                friend_groups.erase(friend_groups.begin() + v_idx);
            }
        } else if(u_idx != -1) {
            friend_groups[u_idx].insert(v);
        } else if(v_idx != -1) {
            friend_groups[v_idx].insert(u);
        } else {
            set<int> new_group;
            new_group.insert(u);
            new_group.insert(v);
            friend_groups.push_back(new_group);
        }
    }
    
    long long total_sum = 0;
    set<int> grouped_indices; // Keeps track of 1-based indices that belong to a group

    // 1. Calculate the minimum of each group and add to total_sum
    for(const auto& group : friend_groups) {
        int min_val = 2e9; // Start with a very large number
        
        for(int member : group) {
            // Convert 1-based member index to 0-based character index
            int val = characters[member - 1]; 
            if(val < min_val) {
                min_val = val;
            }
            grouped_indices.insert(member); // Mark as grouped
        }
        total_sum += min_val;
    }

    // 2. Add the remaining standalone characters that don't belong to any group
    for(int i = 1; i <= n; i++) {
        if(grouped_indices.find(i) == grouped_indices.end()) {
            total_sum += characters[i - 1];
        }
    }

    cout << total_sum << endl;

    return 0;
}
