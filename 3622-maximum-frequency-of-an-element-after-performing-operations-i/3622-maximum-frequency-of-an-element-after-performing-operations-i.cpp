#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // Count frequencies of original numbers
        unordered_map<int,int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        
        // Using a map for difference‐array / sweep line: key = target value, value = delta
        map<int,int> diff;
        for (int x : nums) {
            // mark range of values to which x can be adjusted: [x − k, x + k]
            diff[x - k] += 1;
            diff[x + k + 1] -= 1;
            // also ensure the value x itself is present so we consider targets equal to original values
            if (diff.find(x) == diff.end()) {
                diff[x] += 0;
            }
        }
        
        int ans = 0;
        int running = 0;  // number of elements whose ranges cover the current target value
        for (auto & [val, delta] : diff) {
            running += delta;
            int originalCount = cnt.count(val) ? cnt[val] : 0;
            // We can pick up to numOperations elements from those that can reach `val`
            // Total reachable = running
            // Of that, originalCount are already equal to val without using operations.
            // So we can add up to min(numOperations, reachable−originalCount) to originalCount.
            int possible = originalCount + min(numOperations, running - originalCount);
            ans = max(ans, possible);
        }
        
        return ans;
    }
};
