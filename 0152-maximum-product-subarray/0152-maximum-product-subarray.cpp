class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curMin = nums[0];
        int curMax = nums[0];
        int maxprod = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                swap(curMax, curMin);
            }
            curMin = min(nums[i], nums[i]*curMin);
            curMax = max(nums[i], nums[i]*curMax);
            maxprod = max(maxprod,curMax);
        }
        return maxprod;
    }
};