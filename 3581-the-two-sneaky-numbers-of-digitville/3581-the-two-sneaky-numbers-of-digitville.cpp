class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(auto it:freq){
            if (it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};