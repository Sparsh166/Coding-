class Solution {
public:
    int maximum(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }

    int summation(vector<int>& nums){
        int n = nums.size();
        int summ=0;
        for(int i=0;i<n;i++){
            summ+=nums[i];
        }
        return summ;
    }
    
    int solution(vector<int>& nums,int numbers, int k){
        int n = nums.size();
        int parts = 1;
        int sum =0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=numbers){
                sum+=nums[i];
            }
            else{
                parts++;
                sum=nums[i];
            }
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int k) {
     int low = maximum(nums);
     int high = summation(nums);
     while(low<=high){
        int mid = (low+high)/2;
        int parts = solution(nums,mid,k);
            if(parts<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low; 
    }    
};