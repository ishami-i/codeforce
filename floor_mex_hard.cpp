#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n + 1);
    for (int k = 1; k <= n; k++) {
        cin >> a[k];
    }

    vector<long long> pow2(n + 2);
    pow2[0] = 1;
    for (int i = 1; i <= n + 1; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    vector<int> diff(n + 2, 0);
    for (int k = 1; k <= n; k++) {
        long long ak = a[k];
        long long lo = ak * (long long)k;
        if (lo > n - 1) continue;
        
        long long hi = (ak + 1) * (long long)k - 1;
        long long r = min(hi, (long long)(n - 1));
        diff[(int)lo] += 1;
        diff[(int)r + 1] -= 1;
    }

    vector<char> inM(n, 0);
    long long cur = 0;
    for (int y = 0; y < n; y++) {
        cur += diff[y];
        inM[y] = (cur == 0);
    }

    vector<int> idxOf(n, -1);
    int p = 0;
    for (int y = 0; y < n; y++) {
        if (inM[y]) {
            p++;
            idxOf[y] = p;
        }
    }

    vector<int> nextIdx(n + 1);
    nextIdx[n] = p + 1;
    for (int x = n - 1; x >= 0; x--) {
        nextIdx[x] = inM[x] ? idxOf[x] : nextIdx[x + 1];
    }
    vector<int> prevIdx(n);
    int last = 0;
    for (int x = 0; x < n; x++) {
        if (inM[x]) last = idxOf[x];
        prevIdx[x] = last;
    }

    vector<pair<int, int>> cons;
    cons.reserve((size_t)n); 
    for (int k = 1; k <= n; k++) {
        long long ak = a[k];
        if (ak <= 0) continue;
        for (long long v = 0; v < ak; v++) {
            long long lo = v * (long long)k;
            if (lo > n - 1) break;
            long long hi = min((v + 1) * (long long)k - 1, (long long)(n - 1));
            int l = nextIdx[(int)lo];
            int r = prevIdx[(int)hi];
            if (l < 1 || r > p || l > r) continue; 
            
            cons.push_back({l, r});
        }
    }
    
    sort(cons.begin(), cons.end(), [](const pair<int, int>& A, const pair<int, int>& B) {
        if (A.first != B.first) return A.first > B.first;
        return A.second < B.second;
    });

    int minR = p + 1;
    long long coveredLen = 0;
    long long answer = 1;
    for (auto &pr : cons) {
        int l = pr.first, r = pr.second;
        if (r < minR) {
            long long len = r - l + 1;
            coveredLen += len;
            answer = answer * ((pow2[(size_t)len] - 1 + MOD) % MOD) % MOD;
            minR = r;
        }
    }

    long long freeCount = (long long)p - coveredLen;
    if (freeCount < 0) freeCount = 0; 
    answer = answer * pow2[(size_t)freeCount] % MOD;

    cout << answer << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
