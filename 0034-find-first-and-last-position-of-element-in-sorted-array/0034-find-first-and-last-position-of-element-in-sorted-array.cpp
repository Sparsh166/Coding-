class Solution {
public:
    int first(int target, vector<int>& nums) {
        int n = nums.size();
        bool present = false;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == nums[mid]) {
                high = mid-1;
                present = true;
            } else if (target >= nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(present==false){
            return -1;
        }
        return low;
    }

    int last(int target, vector<int>& nums){
        int n = nums.size();
        bool present = false;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == nums[mid]) {
                low = mid+1;
                present = true;
            } else if (target >= nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(present==false){
            return -1;
        }
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target){
        int F = first(target, nums);
        int L = last(target, nums);

        return {F, L};

    }
};