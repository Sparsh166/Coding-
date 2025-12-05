class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int diff = 0;
        int count = 0;
        int prefix=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        for(int i=0;i<n-1;i++){
            prefix+=nums[i];
            diff = sum-prefix;
            if((prefix%2==(diff%2))){
                count++;
            }
        }
        return count;
    }
};