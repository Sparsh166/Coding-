class Solution {
public:
    int maxim(vector<int>& nums){
        int n = nums.size();
        long long maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max((long long)nums[i],maxi);
        }
        return maxi;
    }
    int divisible(vector<int>& nums, int number){
        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=(nums[i]+number-1)/number;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) { 
        int low = 1;
        long long high = maxim(nums);
        int ans = -1;
        while(low<=high){
            long long mid = (low+high)/2;
            long long sum = divisible(nums,mid);
            if(sum<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};