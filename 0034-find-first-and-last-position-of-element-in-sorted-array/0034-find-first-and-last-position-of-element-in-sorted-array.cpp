class Solution {
public:
    int first(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        bool present = false;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                present = true;
                high = mid-1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if (present == false){
            return -1;
        }
        return low;
    }
    int last(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        bool present = false;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                present = true;
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if (present == false){
            return -1;
        }
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums,target);
        int l = last(nums,target);
        return {f,l};
    }
};