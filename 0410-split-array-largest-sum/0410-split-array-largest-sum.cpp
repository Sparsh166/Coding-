class Solution {
public:
    int maxim(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    int suma(vector<int>& nums){
        int n = nums.size();
        int summ = 0;
        for(int i=0;i<n;i++){
            summ+=nums[i];
        }
        return summ;
    }
    int arr(vector<int>& nums, int number){
        int n = nums.size();
        int count=1;
        int num = 0;
        for(int i=0;i<n;i++){
            if(nums[i]+num<=number){
            num+=nums[i];
        }
        else{
            count++;
            num=nums[i];
        }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = maxim(nums);
        int high = suma(nums);
        while(low<=high){
            int mid = (low+high)/2;
            int count = arr(nums,mid);
            if(count<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};