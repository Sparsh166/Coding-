class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        map<int,int>mpp;
        int ans = original;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.first==ans){
                ans = ans*2;
            }
        }
        return ans;

    }
};