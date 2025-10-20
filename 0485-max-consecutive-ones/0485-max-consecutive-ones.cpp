class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size();
        int count = 0;
        int ans = 0;
        for(int i =0;i<n;i++){
            if(XOR^nums[i]!=0){
                count++;
                ans = max(count,ans);
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
};