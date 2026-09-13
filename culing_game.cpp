#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Node {
    long long sum;
    long long max_diff;
};

int N;
vector<long long> A;
vector<Node> tree;

Node merge_nodes(const Node& left, const Node& right) {
    Node parent;
    parent.sum = left.sum + right.sum;
    parent.max_diff = max(left.max_diff, right.max_diff - left.sum);
    return parent;
}

void update(int node, int start, int end, int idx, long long val, bool activate) {
    if (start == end) {
        if (activate) {
            tree[node].sum = val;
            tree[node].max_diff = val;
        } else {
            tree[node].sum = 0;
            tree[node].max_diff = -1e18;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(2 * node, start, mid, idx, val, activate);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val, activate);
    }
    
    tree[node] = merge_nodes(tree[2 * node], tree[2 * node + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return {0, (long long)-1e18};
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    Node left = query(2 * node, start, mid, l, r);
    Node right = query(2 * node + 1, mid + 1, end, l, r);
    return merge_nodes(left, right);
}

int count_forfeits(int node, int start, int end, long long current_pref_sum) {
    if (start == end) {
        if (tree[node].sum > 0 && tree[node].sum > current_pref_sum) {
            return 1;
        }
        return 0;
    }
    
    if (tree[node].max_diff <= current_pref_sum) {
        return 0;
    }
    
    int mid = (start + end) / 2;
    int left_forfeits = count_forfeits(2 * node, start, mid, current_pref_sum);
    long long new_pref_sum = current_pref_sum + tree[2 * node].sum;
    int right_forfeits = count_forfeits(2 * node + 1, mid + 1, end, new_pref_sum);
    return left_forfeits + right_forfeits;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    A.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    N = n;
    tree.assign(4 * N + 1, {0, (long long)-1e18});
    for (int i = 1; i <= n; i++) {
        update(1, 1, N, i, A[i], true);
    }
    vector<int> answers(n + 1);
        for (int i = 0; i < n; i++) {
        if (i > 0) {
            update(1, 1, N, p[i], A[p[i]], false);
        }
        answers[i] = count_forfeits(1, 1, N, 0);

        if (tree[1].sum > 0) {
            answers[i]--;
        }
    }
    
    // Print results
    for (int i = 0; i < n; i++) {
        cout << answers[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
