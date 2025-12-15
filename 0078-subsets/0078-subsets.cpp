class Solution {
public:
    void helper(vector<int>& nums, int ind, vector<int>& arr, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(arr);
            return;
        }

        // include
        arr.push_back(nums[ind]);
        helper(nums, ind + 1, arr, ans);

        // exclude
        arr.pop_back();
        helper(nums, ind + 1, arr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(nums, 0, arr, ans);
        return ans;
    }
};
