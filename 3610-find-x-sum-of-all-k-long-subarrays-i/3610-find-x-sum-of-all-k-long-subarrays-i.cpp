#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> answer;
        if (n < k) return answer;

        // Sliding-window counts
        unordered_map<int,int> freq;

        // Build first window
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }

        // Helper to compute x-sum of current window
        auto computeXsum = [&]() {
            // Create vector of (value, count)
            vector<pair<int,int>> v;
            v.reserve(freq.size());
            for (auto &p : freq) {
                v.emplace_back(p.first, p.second);
            }
            // Sort by: descending count, then descending value
            sort(v.begin(), v.end(), [&](const pair<int,int>& a, const pair<int,int>& b){
                if (a.second != b.second) return a.second > b.second;
                return a.first > b.first;
            });
            long long sum = 0;
            int taken = 0;
            for (auto &p : v) {
                if (taken >= x) break;
                int val = p.first;
                int cnt = p.second;
                sum += (long long)val * cnt;
                taken++;
            }
            // If fewer than x distinct, sum of whole window:
            if ((int)v.size() < x) {
                // But note: the above already summed each distinct value * its count,
                // which effectively sums the whole window since it includes all distinct.
            }
            return (int)sum;
        };

        // Compute for first window
        answer.push_back(computeXsum());

        // Slide the window
        for (int i = k; i < n; i++) {
            int in = nums[i];
            int out = nums[i - k];

            // Remove outgoing
            auto oit = freq.find(out);
            if (oit != freq.end()) {
                oit->second--;
                if (oit->second == 0) {
                    freq.erase(oit);
                }
            }

            // Add incoming
            freq[in]++;

            // Compute & record
            answer.push_back(computeXsum());
        }

        return answer;
    }
};
