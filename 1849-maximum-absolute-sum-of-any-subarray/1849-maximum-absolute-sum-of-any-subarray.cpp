class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
     int maxSum = INT_MIN;
     int minSum = INT_MAX;
     int curPsum = 0;
     int curNsum = 0;
     int ans = 0;
     int n = nums.size();
     for(int i=0;i<n;i++){
        curPsum += nums[i];
        maxSum = max(curPsum,maxSum);
        if(curPsum<0){
            curPsum =0;
        }

        curNsum+=nums[i];
        minSum = min(curNsum,minSum);
        if(curNsum>0){
            curNsum = 0;
        }
     }
     return max(maxSum , abs(minSum));
    }
};