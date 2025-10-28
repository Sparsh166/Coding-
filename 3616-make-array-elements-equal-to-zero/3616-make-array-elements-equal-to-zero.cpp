class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int lsum = 0;
        int rsum = 0;
        int count =0;
        int n = nums.size();
        vector<int>zero;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero.push_back(i);
            }
        }
        for(int i=1;i<n;i++){
            nums[i] = nums[i]+nums[i-1];
        }
        for(int i =0;i<zero.size();i++){
            if(nums[n-1]-nums[zero[i]]==nums[zero[i]]+1 || nums[n-1]-nums[zero[i]]==nums[zero[i]]-1){
                count++;
            }
            if(nums[n-1]-nums[zero[i]]==nums[zero[i]]){
                count = count+2;
            }
        }
        return count;
    }
};