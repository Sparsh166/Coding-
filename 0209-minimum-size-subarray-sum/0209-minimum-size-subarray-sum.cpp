class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int currentsum = 0;
        int curlen = INT_MAX;
        int low = 0;
        int high = 0;
        while(high<n){
            currentsum +=nums[high];
            high++;

            while(currentsum>=target){
                int windowsize = high-low;
                curlen = min(curlen,windowsize);
                currentsum -= nums[low];
                low++;

            }
        }
        return (curlen==INT_MAX)?0:curlen;
    }
};