class Solution {
public:
    int maxim(vector<int>& nums){
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxi = max(nums[i],maxi);
        }
        return maxi;
    }
    int summ(vector<int>& nums){
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return sum;
    }
    int arr(vector<int>& nums, int number){
        int count = 1;
        int n = nums.size();
        int num = 0;
        for(int i=0;i<n;i++){
            if(nums[i]+num<=number){
                num+=nums[i];
            }
            else{
                count++;
                num = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = maxim(nums);
        int high = summ(nums);
        while(low<=high){
            int mid = (low+high)/2;
            int count = arr(nums,mid);
            if(count<=k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};