class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        int j = 0;
        for(int i =0;i<n;i++){
            if (nums[i]!= target){
                swap(nums[j],nums[i]);
                j++;
            }
        }
        
    }
};