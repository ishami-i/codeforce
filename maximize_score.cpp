#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// Problem: array of length 2n, each value in [1..n] appears exactly twice.
// Repeatedly pick a value x, let l/r be the leftmost/rightmost occurrence of
// x in the CURRENT array, score += (r-l+1)^2, delete a[l..r], reindex.
// Maximize total score.
//
// Key fact (proved in the editorial via an exchange argument):
// There's always an optimal strategy where every operation is "full" -- it
// removes exactly the ORIGINAL span between a pair's two occurrences, with
// nothing already deleted from inside it. Why swapping to a "full" op never
// hurts: if a value's original span has length A, but by the time we pick it
// some inner chunk of length B was already removed earlier (so we only score
// (A-B)^2 for it, plus whatever the B-chunk scored, at most B^2), then
// (A-B)^2 + B^2 <= A^2 always. So doing the full A-span first (before
// touching anything inside it) is at least as good.
//
// Consequence: the whole process is equivalent to PARTITIONING the array
// into disjoint blocks, where each block is either:
//   - a single leftover position (its partner got "absorbed" into some
//     other block, or never gets a block of its own), contributing 1, or
//   - the entire original interval [l, r] between a value's two occurrences,
//     contributing (r-l+1)^2.
// We just need to choose the partition that maximizes the sum of squares.
// (Crossing pairs, e.g. 1 2 1 2, can't BOTH be taken as full blocks since
// their spans overlap without nesting -- the DP naturally picks whichever
// one is more valuable and leaves the other's second copy as a singleton.)
// ---------------------------------------------------------------------------

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int m = 2 * n;                      // actual array length
        vector<int> a(m + 1);               // 1-indexed array
        for (int i = 1; i <= m; i++) scanf("%d", &a[i]);

        // first_occ[v] = index of the first time we've seen value v so far
        // (0 means "not seen yet"). Used to find the left endpoint l of the
        // pair whenever we hit its second occurrence.
        vector<int> first_occ(n + 1, 0);

        // dp[i] = best achievable score for the prefix a[1..i], treating it
        // as if the array ended at position i (i.e. only using pairs that
        // are fully contained in this prefix).
        vector<long long> dp(m + 1, 0);

        for (int i = 1; i <= m; i++) {
            int v = a[i];
            int l;

            if (first_occ[v] == 0) {
                // This is the FIRST time we see v. It has no completed pair
                // yet, so the only sensible thing right now is to treat
                // position i as a standalone block (score 1). We fake this
                // by setting l = i, which makes the "full pair" branch below
                // collapse to the exact same +1 singleton case.
                first_occ[v] = i;
                l = i;
            } else {
                // This is the SECOND occurrence of v -> l is where its
                // partner sits. Now we have a genuine choice: close the
                // whole pair as one block [l, i], or leave position i as
                // its own singleton block instead.
                l = first_occ[v];
            }

            long long len = (long long)(i - l + 1);

            // Option A: don't use a[i] as part of a pair-block right now --
            //           just tack it on as a lone block of size 1.
            long long optionSingleton = dp[i - 1] + 1;

            // Option B: close the full block [l, i] here. Everything before
            //           l is scored independently via dp[l-1] (whatever's
            //           optimal for that separate prefix).
            long long optionFullPair = dp[l - 1] + len * len;

            dp[i] = max(optionSingleton, optionFullPair);
        }

        // dp[m] = best score using the whole array.
        printf("%lld\n", dp[m]);
    }
    return 0;
}
