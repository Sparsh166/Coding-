class Solution {
public:
    int maxium(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(nums[i],maxi);
        }
        return maxi;
    }
    int divisor(vector<int>& nums,int number){
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]+number-1)/number;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = maxium(nums);
        int result =-1;
        while(low<=high){
            int mid = (low+high)/2;
            int ans = divisor(nums,mid);
            if(ans<=threshold){high=mid-1;}
            else{low=mid+1;}
        }
        return low;
    }
};