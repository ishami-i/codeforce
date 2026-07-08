#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

 // allocating prefix sum globally to reduce the stack overflow
 int pre[100005][4];


int main() {
    // setup usaco file I/O
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    if(!(cin >> n >> q)) return 0;

    for(int i = 1; i <= n; i++) {
        int breed;
        cin >> breed;

        pre[i][1] = pre[i - 1][1];
        pre[i][2] = pre[i - 1][2];
        pre[i][3] = pre[i - 1][3];

        pre[i][breed]++;
    }
    while(q--) {
        int a, b;
        cin >> a >> b;
        int count_h = pre[b][1] - pre[a - 1][1];
        int count_g = pre[b][2] - pre[a - 1][2];
        int count_j = pre[b][3] - pre[a - 1][3];

        cout << count_h << " " << count_g << " " << count_j << "\n";
    }

    return 0;
}
   