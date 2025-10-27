class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        map<int,int>freq;
        if(n<2){
            for(int i=0;i<n;i++){
                ans.push_back(nums[i]);
            }
        }
        else{
            for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(auto it: freq){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        }
        return ans;
    }
};